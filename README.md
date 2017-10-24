# timeso
Simple helper C++ library to convert string to chrono time_point and back.

The folder structure comes from eclipse. Requires boost_date_time library, Debug additionally depends on https://github.com/bombela/backward-cpp it links, dynamically, against it, the name I choose for it as a dynamic library is backwardSTso and a macro header (only) found in https://github.com/jouven/comuso.

There are some fixed paths on the make files, "-L/usr/local/lib" and "-L/home/jouven/mylibs/debug" might need to be edited/removed depending on the circumstances.
