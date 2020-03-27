/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_UTILITY_SOURCE_PROCESS_THREAD_IMPL_H_
#define WEBRTC_MODULES_UTILITY_SOURCE_PROCESS_THREAD_IMPL_H_

#include <list>

#include "process_thread.h"
#include "../system_wrappers/include/critical_section_wrapper.h"
#include "../system_wrappers/include/event_wrapper.h"
#include "../system_wrappers/include/thread_wrapper.h"
#include "typedefs.h"

namespace yuntongxunwebrtc {
class ProcessThreadImpl : public ProcessThread
{
public:
    ProcessThreadImpl();
    virtual ~ProcessThreadImpl();

    virtual int32_t Start();
    virtual int32_t Stop();

    virtual int32_t RegisterModule(Module* module);
    virtual int32_t DeRegisterModule(const Module* module);

protected:
    static bool Run(void* obj);

    bool Process();

private:
    typedef std::list<Module*> ModuleList;
    EventWrapper&           _timeEvent;
    CriticalSectionWrapper* _critSectModules;
    ModuleList              _modules;
    ThreadWrapper*          _thread;
};
}  // namespace yuntongxunwebrtc

#endif // WEBRTC_MODULES_UTILITY_SOURCE_PROCESS_THREAD_IMPL_H_