/*
 * Copyright 2013 Google Inc.
 * Copyright 2014-2016 the libsecp256k1 contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.bitcoin;

public class NativeSha256 {
    /**
     * Computes the SHA-256 hash of the given data in native code.
     *
     * @param data The data which is to be hashed
     */
    public static byte[] hash(byte[] data) {
        return secp256k1_sha256(data, data.length);
    }

    private static native byte[] secp256k1_sha256(byte[] data, int dataLen);
}
