FILE(REMOVE_RECURSE
  "../srv_gen"
  "../srv_gen"
  "../src/estop/srv"
  "CMakeFiles/ROSBUILD_gensrv_lisp"
  "../srv_gen/lisp/Empty.lisp"
  "../srv_gen/lisp/_package.lisp"
  "../srv_gen/lisp/_package_Empty.lisp"
  "../srv_gen/lisp/estopSignal.lisp"
  "../srv_gen/lisp/_package.lisp"
  "../srv_gen/lisp/_package_estopSignal.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
