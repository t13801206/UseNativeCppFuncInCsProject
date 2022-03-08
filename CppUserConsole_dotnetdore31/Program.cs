using System;
using System.Runtime.InteropServices;

namespace CppUserConsole_dotnetdore31
{
    class Program
    {
        [DllImport("CppNativeForDotnetCore31.dll")]
        static extern void CheckOpenCV();
        
        [DllImport("CppNativeForDotnetCore31.dll")]
        static extern void SendCommand(char[] command, int commandLength);

        static void Main(string[] args)
        {
            // OSが何ビットで動作しているか確認
            Console.WriteLine($"OS : {(Environment.Is64BitOperatingSystem ? "64bit" : "32bit")}");
            // プロセスが何ビットで動作しているか確認
            Console.WriteLine($"プロセス : {(Environment.Is64BitProcess ? "64bit" : "32bit")}");
            
            CheckOpenCV();
            var command = new [] { 'a', 'Z', '0', '9' };
            SendCommand(command, command.Length);
           
            Console.WriteLine("Hello World!");
        }
    }
}
