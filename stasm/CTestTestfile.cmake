# CMake generated Testfile for 
# Source directory: /home/yx/fr/project/imageParser/stasm4.1.0
# Build directory: /home/yx/fr/project/imageParser/stasm4.1.0
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(TestMinimal "./minimal")
ADD_TEST(TestMinimal2 "./minimal2")
ADD_TEST(TestStasm "./stasmMain" "../data/testface.jpg")
ADD_TEST(TestStasmMulti "./stasmMain" "-m" "../tests/data/testmulti.jpg")
ADD_TEST(TestStasmMulti2 "./stasmMain" "-d" "-m" "-s" "-c" "../tests/data/testmulti.jpg")
ADD_TEST(TestStasm68 "./stasmMain" "-i" "-n" "68" "../data/testface.jpg")
ADD_TEST(TestSwas "./swas" "-f" "../tests/data/testface.shape")
ADD_TEST(TestTasm "./tasms" "-d" "test_tasmout" "-w" "../tasm/shapes/muct77_short.shape")
