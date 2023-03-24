/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 *  Manage the remote camera service native functions.
 */
#pragma once
#include <jni.h>

namespace android {
namespace webcam {

enum Status {
    OK = 0,
    ERROR = 1,
};

class ScopedAttach {
  public:
    ScopedAttach(JavaVM* vm, JNIEnv** env) : vm_(vm) { vm_->AttachCurrentThread(env, NULL); }

    ~ScopedAttach() { vm_->DetachCurrentThread(); }

  private:
    JavaVM* vm_;
};

}  // namespace webcam
}  // namespace android