file(REMOVE_RECURSE
  "liblib1.a"
  "liblib1.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/lib1.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
