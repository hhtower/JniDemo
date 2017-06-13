#include "net_mapout_jni_JNILoader.h"
#include "hello.h"
#include <string>

/**
 * std::string 转  jstring
 */
jstring str2jstring(JNIEnv* env, std::string str)
{
    const char* pStr = str.c_str();
    int        strLen    = strlen(pStr);
    jclass     jstrObj   = env->FindClass("java/lang/String");
    jmethodID  methodId  = env->GetMethodID(jstrObj, "<init>", "([BLjava/lang/String;)V");
    jbyteArray byteArray = env->NewByteArray(strLen);
    jstring    encode    = env->NewStringUTF("UTF-8");
    env->SetByteArrayRegion(byteArray, 0, strLen, (jbyte*)pStr);
    return (jstring)env->NewObject(jstrObj, methodId, byteArray, encode);
}

/**
 * 实现头文件
 */
JNIEXPORT jstring JNICALL Java_net_mapout_jni_JNILoader_sayHello
  (JNIEnv *env, jclass jclass){
    return str2jstring( env, sayHello() );
}