����libvpxʱ

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
 $ mkdir build
 $ cd build
 $ ../libvpx/configure <options>
 $ make

 ./../libvpx/configure --target=x86-win32-vs9 --enable-static-msvcrt --disable-install-bins
 ����yasm�����Ŀ¼
 �޸Ĺ�������yasm���� . -I..\..\libvpx