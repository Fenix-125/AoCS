## Lab 1 (performance testing)

    Topic:      Test numeric-string casting tools performance
    Task:       Casting of a number (double) into a string. Test it on input file.
                Result -- sum of all chars in strings and their average length.
    Task Number:    4
    Author:         Yuriy Pasichnyk 
----
### To start run ```./run.sh``` or ```bash run.sh``` (details in the usage section)

### Project Structure

    - [cmake-build-debug]   # build directory
    - include               # headers
    - scripts               # scripts
    - src                   # source files
    - [tmp]                 # generated files
        - [doubles_1MB.txt] # generated input data
        - [resul.txt]       # temporary file with results
        
    ## Names in [] are generated. 

    test_double_cast_performance.py - test all cast methods
    test_file_gen.py - generate data file
    build.sh - prepare (create dirs and run cmake) project for work and generate data
    run.sh - runs tests and if nesesary runs build.sh

### Requirements

- Qt5
- Boost
- python 3.8
- CMake 3.15
- Bash
- PVS studio (Optional, in cmake is a commented target)

### Implemented

    StreamCast - on streams
    ToStringCast - on to_string implementation
    BoostLexicalCast - on boost tools
    QsNumberCast - on qt tools
    
### Usage examples

    ## for etch cast test is runed by default 6 times
    $ ./run.sh      # if it was build (runed at least once before)
    Test cast double to string by:
    StreamCast(1000016 chars):	50295  VALID
    ToStringCast(1000016 chars):	47849  VALID
    BoostLexicalCast(1052297 chars):	59497  VALID
    QsNumberCast(1000016 chars):	19333  VALID
   
<br>
    
    ## n -- how many times to ran tests for etch method
    ## input_file.txt -- file with row separate doubles
    ## output_tmp_file.txt -- used to store the temporary converted doubles and test results
    ##                                        n    input_file.txt      output_tmp_file.txt
    $ scripts/test_double_cast_performance.py 1000 tmp/doubles_1MB.txt tmp/resul.txt
    Test cast double to string by:
    StreamCast(1000016 chars):	49211  VALID
    ToStringCast(1000016 chars):	43945  VALID
    BoostLexicalCast(1052297 chars):	55675  VALID
    QsNumberCast(1000016 chars):	17414  VALID

<br>

    ## k -- can be a number form 1 to 4
    ## input_file.txt -- file with row separate doubles
    ## output_tmp_file.txt -- used to store the converted doubles and test results
    ##                                   k input_file.txt      output_tmp_file.txt
    $ cmake-build-debug/double_cast_test 3 tmp/doubles_1MB.txt tmp/resul.txt
    ###### Casting double using BoostLexicalCast ######
    Method Name:		BoostLexicalCast
    Tool description:
    	Casting double to string using 'boost::lexical_cast' function.
    
    Speed test:
    	Seconds:			0
    	Milliseconds:		59
    	Microseconds:		59384
    
    Characters number:		1052297
    Avg numbers length:		18.3104
