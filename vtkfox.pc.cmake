prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${prefix}/lib
includedir=${prefix}/include/vtkfox
 
Name: vtkfox
Description: FOX/VTK Widget and Interactor
Version: @VTKFOX_VERSION@
Requires.private: 
Libs: -L${libdir} -lvtkfox
Cflags: -I${includedir}
Cflags.private: 
