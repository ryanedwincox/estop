FILE(REMOVE_RECURSE
  "../srv_gen"
  "../srv_gen"
  "../src/estop/srv"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "../srv_gen/cpp/include/estop/Empty.h"
  "../srv_gen/cpp/include/estop/estopSignal.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
