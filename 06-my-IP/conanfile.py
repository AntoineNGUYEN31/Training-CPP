from conans import ConanFile, CMake, tools


class HelloConan(ConanFile):
    name = "myIP"
    version = "0.1"
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of Hello here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"
    #requires = "libcurl/7.60.0@bincrafters/stable"
    #requires = "simpleCURL/0.0.1@antoine/centos7"
    requires = "simpleCURL/0.0.1@demo/iso"
    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        #cmake.configure()
        cmake.build()

        # Explicit way:a
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["myIP"]

