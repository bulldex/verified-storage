# Merkle Patricia Trie

![Language](https://img.shields.io/badge/language-C++14-blue)
[![LICENSE](https://img.shields.io/github/license/verified-network/verified-storage)](LICENSE)
![Status](https://img.shields.io/badge/status-unstable-red)
[![Website](https://img.shields.io/website?down_color=lightgrey&down_message=offline&up_color=blue&up_message=online&url=https://www.verified.network/)](https://www.verified.network/)
<!-- [![GitHub Issues](https://img.shields.io/github/issues/verified-network/verified-storage)](https://github.com/verified-network/verified-storage/issues) -->
<!-- ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/verified-network/verified-storage) -->
<!-- ![Sonar Quality Gate](https://img.shields.io/sonar/:metric/:component?server=https%3A%2F%2Fsonarcloud.io&sonarVersion=4.2) -->

> This is an implementation of Modified Merkle Patricia Trie as mentioned in Ethereum Paper.

## Contact

- Report bugs, issues or feature requests using [GitHub issues](https://github.com/verified-network/verified-storage/issues/new).

## Install

### Building from the source

#### Get the source code

Git and Github are used to maintain the source code. Clone the repository by:

```shell
git clone https://github.com/verified-network/verified-storage.git

cd verified-storage
```

#### Install CMake
CMake is used to control the build configuration of the project. Latest version of CMake is required (at the time of writing 3.16.0). We strongly recommend you to install CMake by downloading and unpacking and unpacking the binary distribution of the latest version available on [**the CMake download page**](https://cmake.org/download/).

The CMake package available on the operating system can also be used provided it meets the minimum version requirement.

#### Build
Configure the project build with the following command and create the `build` directory with the confgurations

```shell
mkdir build     # Create a build directory
cd build        # Change directory to build directory
cmake ..        # Configure the project.
cmake --build . # Build all default targets.
```

**OR**

```shell
cmake -H. -Bbuild -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=Release   # Configure the project in the build directory
 
cmake --build build --config Release                                    # Build all default targets as release targets.
```

On **Windows** we support Visual Studio 2017, and 2019. You should generate a Visual Studio solution file (`.sln`) for the 64-bit architecture via the following command:

* **Visual Studio 2019**: `cmake .. -G "Visual Studio 16 2019" -A x64`

After the necessary dependencies have been downloaded and built and the solution has been generated, `verified-storage.sln` can be found in the `build` directory.

## Tools

The Verified Storage includes the following tools in addition to the Storage:
* **[constants](constants/)**: A list of macros, aliases and enums.
* **[utils](utils/)**: A utility functionality used as utility
* **[rlp](rlp/)**: A RLP encoder/decoder tool
* **[keccak](keccak/)**: Keccak Hashing implementation

## License

[![LICENSE](https://img.shields.io/github/license/verified-network/verified-storage)](LICENSE)

All contributions are made under the [MIT License](https://opensource.org/licenses/MIT). See [LICENSE](LICENSE).

## Things to be Added

- [x] Integration with LevelDB
- [x] Implement RLP and use for encoding values
- [x] Implement KECCAK256 and replace sha256 hash generation by KECCAK256
- [x] Try to get rid of all the pointers.
- [x] Integrate with boost library
- [x] Add CMakeList
- [x] Add Hunter
- [x] Integrate hunter with boost library
- [x] Integrate hunter with leveldb library
- [x] Create Toolchain compatible for Linux
- [x] Create Toolchain compatible for Win32/64
- [ ] Create Toolchain compatible for LLVM
- [x] Add Build Instructions in the Readme
- [x] ~~Add Makefile~~
- [ ] Create Code Documentation
- [ ] Create Library Documentation
- [ ] Perform Static Code Analysis
- [ ] Check memory footprint of the entire library
- [ ] Improve memory foorprint and efficiency of library (If necessary)

**NOTE:** Currently this library is under development and unstable, NOT FOR PRODUCTION.
