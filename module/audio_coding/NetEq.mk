TOOLSET := target
TARGET := NetEq

OUTPUT:= ../../$(OBJDIR)/$(TARGET)
INPUT := ./neteq/source
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
	'-DWEBRTC_DETECT_ARM_NEON' \
	'-DWEBRTC_CLOCK_TYPE_REALTIME' \
	'-DWEBRTC_THREAD_RR' \
	'-DWEBRTC_ANDROID_OPENSLES' \
	'-DNETEQ_VOICEENGINE_CODECS' \
	'-DSCRATCH' \
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
    -I../. \
	-Ineteq/include \
	-Ineteq/source  \
	-Icodecs/cng/include \
	-I../signalprocess/include

OBJS :=  $(OUTPUT)/accelerate.o \
	$(OUTPUT)/automode.o \
	$(OUTPUT)/bgn_update.o \
	$(OUTPUT)/bufstats_decision.o \
	$(OUTPUT)/cng_internal.o \
	$(OUTPUT)/codec_db.o \
	$(OUTPUT)/correlator.o \
	$(OUTPUT)/dsp.o \
	$(OUTPUT)/dsp_helpfunctions.o \
	$(OUTPUT)/dtmf_buffer.o \
	$(OUTPUT)/dtmf_tonegen.o \
	$(OUTPUT)/expand.o \
	$(OUTPUT)/mcu_address_init.o \
	$(OUTPUT)/mcu_dsp_common.o \
	$(OUTPUT)/mcu_reset.o \
	$(OUTPUT)/merge.o \
	$(OUTPUT)/min_distortion.o \
	$(OUTPUT)/mix_voice_unvoice.o \
	$(OUTPUT)/mute_signal.o \
	$(OUTPUT)/normal.o \
	$(OUTPUT)/packet_buffer.o \
	$(OUTPUT)/peak_detection.o \
	$(OUTPUT)/preemptive_expand.o \
	$(OUTPUT)/random_vector.o \
	$(OUTPUT)/recin.o \
	$(OUTPUT)/recout.o \
	$(OUTPUT)/rtcp.o \
	$(OUTPUT)/rtp.o \
	$(OUTPUT)/set_fs.o \
	$(OUTPUT)/signal_mcu.o \
	$(OUTPUT)/split_and_insert.o \
	$(OUTPUT)/unmute_signal.o \
	$(OUTPUT)/webrtc_neteq.o

$(MYLIB)/libNetEq.a:$(OBJS)
	mkdir -p $(MYLIB)
	 $(AR) $(ARFLAGS) $@ $(OBJS)

$(OUTPUT)/%.o:$(INPUT)/%.c
	mkdir -p $(OUTPUT)
	$(CC) -c -o $@ $(CFLAGS_Release) $(DEFS_Release)  $(CFLAGS_C_Release) $(INCS_Release) $<
