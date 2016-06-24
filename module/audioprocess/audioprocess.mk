TOOLSET := target
TARGET := audioprocess

OUTPUT:= ../../$(OBJDIR)/$(TARGET)
INPUT := ./source
MYLIB = ../../$(OUTLIB)

DEFS_Release := '-DWEBRTC_SVNREVISION="n/a"' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_GPU=1' \
	'-DUSE_OPENSSL=1' \
	'-DENABLE_EGLIMAGE=1' \
	'-DUSE_SKIA=1' \
	'-DWEBRTC_LINUX' \
	'-DWEBRTC_ANDROID' \
	'-DWEBRTC_ARCH_ARM' \
	'-DWEBRTC_CLOCK_TYPE_REALTIME' \
	'-DWEBRTC_THREAD_RR' \
	'-DWEBRTC_ANDROID_OPENSLES' \
	'-DWEBRTC_NS_FIXED' \
	'-DGOOGLE_PROTOBUF_NO_RTTI' \
	'-DGOOGLE_PROTOBUF_NO_STATIC_INITIALIZER' \
	'-D__STDC_FORMAT_MACROS' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DHAVE_OFF64_T' \
	'-DHAVE_SYS_UIO_H' \
	'-DANDROID_BINSIZE_HACK' \
	'-DANDROID_UPSTREAM_BRINGUP=1' \
	'-DNDEBUG' \
	'-DNVALGRIND' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=0'

# Flags passed to all source files.
CFLAGS_Release := -Werror \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wall \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wextra \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-mthumb \
	-march=armv7-a \
	-mtune=cortex-a8 \
	-mfloat-abi=softfp \
	-mfpu=vfpv3-d16 \
	-fno-tree-sra \
	-Wno-psabi \
	-mthumb-interwork \
	-U__linux__ \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-Wno-error=non-virtual-dtor \
	-I$(ANDROID_INCLUDE) \
	-I$(STLPORT_DIR) \
	-Os \
	-fno-ident \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release := 

# Flags passed to only C++ files.
CFLAGS_CC_Release := -fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wsign-compare \
	-Woverloaded-virtual \
	-Wno-abi

INCS_Release := -I../../.  \
    -I../interface \
    -I../ \
	-I../../system_wrappers/interface \
	-I./include \
	-I./source \
	-I../signalprocess/include \
	-I../utility/include

OBJS :=  $(OUTPUT)/noise_suppression_x.o \
	$(OUTPUT)/nsx_core.o \
	$(OUTPUT)/analog_agc.o \
	$(OUTPUT)/digital_agc.o \
	$(OUTPUT)/delay_estimator.o \
	$(OUTPUT)/delay_estimator_wrapper.o \
	$(OUTPUT)/fft4g.o \
	$(OUTPUT)/ring_buffer.o \
	$(OUTPUT)/echo_cancellation.o \
	$(OUTPUT)/aec_core.o \
	$(OUTPUT)/aec_rdft.o \
	$(OUTPUT)/aec_resampler.o \
	$(OUTPUT)/echo_control_mobile.o \
	$(OUTPUT)/aecm_core.o \
	$(OUTPUT)/audio_buffer.o \
	$(OUTPUT)/audio_processing_impl.o \
	$(OUTPUT)/echo_cancellation_impl.o \
	$(OUTPUT)/echo_control_mobile_impl.o \
	$(OUTPUT)/gain_control_impl.o \
	$(OUTPUT)/high_pass_filter_impl.o \
	$(OUTPUT)/level_estimator_impl.o \
	$(OUTPUT)/noise_suppression_impl.o \
	$(OUTPUT)/splitting_filter.o \
	$(OUTPUT)/processing_component.o \
	$(OUTPUT)/voice_detection_impl.o

$(MYLIB)/libaudioprocess.a:$(OBJS)
	mkdir -p $(MYLIB)
	 $(AR) $(ARFLAGS) $@ $(OBJS)

$(OUTPUT)/%.o:$(INPUT)/%.cc
	mkdir -p $(OUTPUT)
	$(CXX) -c -o $@ $(CFLAGS_Release) $(DEFS_Release)  $(CFLAGS_CC_Release) $(INCS_Release) $<

$(OUTPUT)/%.o:$(INPUT)/%.c
	mkdir -p $(OUTPUT)
	$(CC) -c -o $@ $(CFLAGS_Release) $(DEFS_Release)  $(CFLAGS_C_Release) $(INCS_Release) $<
