#pragma once

#include <IL/OMX_Core.h>
#include "LIBAV_INCLUDES.h"

class OMXInitializer
{
public:
    static OMXInitializer& getInstance()
    {
        static OMXInitializer    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    bool isOpen;
    void init()
    {
        if (!isOpen)
        {
            OMX_Init();
            isOpen = true;
            //ofLogVerbose(__func__) << "";
        }
    }
    void deinit()
    {
        if (isOpen)
        {
            OMX_Deinit();
            isOpen = false;
            //ofLogVerbose(__func__) << "";
        }
    }
private:
    OMXInitializer() {
        //ofLogVerbose(__func__) << "";
        isOpen=false;
        av_register_all();
        avformat_network_init();
        //AV_LOG_INFO
        av_log_set_level(AV_LOG_QUIET);
    };
    OMXInitializer(OMXInitializer const&);
    void operator=(OMXInitializer const&);
};
