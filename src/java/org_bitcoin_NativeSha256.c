#include "org_bitcoin_NativeSha256.h"
#include "src/hash_impl.h"

JNIEXPORT jbyteArray JNICALL Java_org_bitcoin_NativeSha256_secp256k1_1sha256
  (JNIEnv* env, jclass classObject, jbyteArray byteArrayObject, jint dataLen)
{
  jboolean isCopy;
  secp256k1_sha256 sha;
  unsigned char result[32];
  jbyteArray array;

  unsigned char* data = (unsigned char*) (*env)->GetByteArrayElements(env, byteArrayObject, &isCopy);

  secp256k1_sha256_initialize(&sha);
  secp256k1_sha256_write(&sha, data, (int) dataLen);
  secp256k1_sha256_finalize(&sha, result);

  array = (*env)->NewByteArray(env, 32);
  (*env)->SetByteArrayRegion(env, array, 0, 32, (jbyte*)result);

  (*env)->ReleaseByteArrayElements(env, byteArrayObject, (jbyte*) data, 0);

  (void)classObject; (void)byteArrayObject;

  return array;
}
