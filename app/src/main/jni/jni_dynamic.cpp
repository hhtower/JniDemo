#include "hello.h"
#include <jni.h>

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

jstring jniSayHello(JNIEnv *env, jobject obj){
     return str2jstring( env, sayHello() );
}

static const char *jniClassName = "net/mapout/jni/JNILoader";
static JNINativeMethod methods[] = {
        {"sayHello", "()Ljava/lang/String;", (void*)jniSayHello},
};

static int registerNatives(JNIEnv* env) {
    jclass clazz = env->FindClass(jniClassName);
    if (clazz == NULL)
        return JNI_FALSE;

    jint methodSize = sizeof(methods) / sizeof(methods[0]);
    if ( env->RegisterNatives(clazz, methods, methodSize) < 0 )
        return JNI_FALSE;

    return JNI_TRUE;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK)
        return JNI_ERR;

    //注册方法
    if (!registerNatives(env))
        return JNI_ERR;

    result = JNI_VERSION_1_6;
    return result;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv *env = nullptr;
    jint ret = vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (ret != JNI_OK) {
        return ;
    }
}