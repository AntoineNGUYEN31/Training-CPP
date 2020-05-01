Dynamic link
http://derekmolloy.ie/hello-world-introductions-to-cmake/

cona mple
nm example|grep addition
export LD_LIBRARY_PATH=/home/minwoo/TMP/Training-CPP/08-my-math-dynamic/test_package/build/14e0cdfaca04e2acc0576ed87609a7a5c25d6ca6/bincreate . demo/test

conan remote add myremote https://api.bintray.com/conan/antoinenguyen31/test
conan user -p 154eeded64b136eeb03be990621d78a63fd7bf59 -r myremote antoinenguyen31
conan upload myMath/0.1@demo/test -r myremote
