googletest for Unikraft
===================

This is the port of googletest to Unikraft as an external
library. libcxx is required. This library should come at the end of
the dependency list, e.g.,:

	...:$(UK_LIBS)/libunwind:$(UK_LIBS)/compiler-rt:$(UK_LIBS)/libcxxabi:
        $(UK_LIBS)/libcxx:$(UK_LIBS)/newlib:$(UK_LIBS)/googletest:...
					 
This library has a config option called LIBGOOGLETEST_BUILD_MAIN that
builds the gtest_main.cc file. This is because some libraries do not
have any main function in their unit tests and expect googletest to
provide it.
								 
Please refer to the `README.md` as well as the documentation in the
`doc/` subdirectory of the main unikraft repository for further
information.

