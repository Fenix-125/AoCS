//
// Created by fenix on 2/25/20.
//

#ifndef LAB_2_PARALLEL_INTEGRATION_CONFPROGRAMOPTIONS_H
#define LAB_2_PARALLEL_INTEGRATION_CONFPROGRAMOPTIONS_H


class ConfProgramOptions {
public:
    enum status {
        OPT_SUCCESS,
        OPT_HELP_Q,
        OPT_VERSION_Q,
        OPT_ERROR
    };

    ConfProgramOptions();

    ~ConfProgramOptions();

    status parce(int argc, char *argv[]);
};


#endif //LAB_2_PARALLEL_INTEGRATION_CONFPROGRAMOPTIONS_H
