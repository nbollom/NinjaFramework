# Ninja Framework

A collection of utility libraries for use.

### Libraries

* [ninjalog](http://github.com/nbollom/NinjaFramework/tree/master/ninjalog)
* [ninjajson](http://github.com/nbollom/NinjaFramework/tree/master/ninjajson)
* [ninjafile](http://github.com/nbollom/NinjaFramework/tree/master/ninjafile)
* [ninjapack](http://github.com/nbollom/NinjaFramework/tree/master/ninjapack)

### Building

The default cmake config will build all the libraries.

Each library can also be built separately (or with only its required dependencies) by toggling them off using a cmake config utility (cmakegui of ccmake).

There are also test projects for each library that can be turned on separately or in bulk with the BUILD_ALL_TESTS option

#### Linux / OS X

```
mkdir build && cd build
cmake ..
make
```

#### Windows

TBC