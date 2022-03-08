using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CsMainUser
{
    static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main()
        {
            // OSが何ビットで動作しているか確認
            Console.WriteLine($"OS : {(Environment.Is64BitOperatingSystem ? "64bit" : "32bit")}");
            // プロセスが何ビットで動作しているか確認
            Console.WriteLine($"プロセス : {(Environment.Is64BitProcess ? "64bit" : "32bit")}");

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

        }
    }
}
