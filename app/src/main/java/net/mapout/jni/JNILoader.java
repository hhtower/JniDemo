package net.mapout.jni;

/**
 * Created by Tower on 2017/5/25.
 * java jni 接口申明
 */
public class JNILoader {
    static {
        /**
         * JniDemo 为build的so文件名
         */
        System.loadLibrary("JniDemo");
    }

    public static native String sayHello();
    public static native String sayHello(String aa);
}
