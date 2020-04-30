conan create . demo/test

conan remote add myremote https://api.bintray.com/conan/antoinenguyen31/test
conan user -p 154eeded64b136eeb03be990621d78a63fd7bf59 -r myremote antoinenguyen31
conan upload myMath/0.1@demo/test -r myremote
