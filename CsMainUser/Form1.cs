using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Wrapper;

namespace CsMainUser
{    public partial class Form1 : Form
    {
        WrapperClass _wr = new WrapperClass(); //WrapperClassのインスタンスを作成

        public Form1()
        {
            InitializeComponent();

            int[] a = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2 };
            int mx = 0;
            int mxIndex = 0;
            int num = 10;

            MessageBox.Show("int[] a = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2 }");

            _wr.Max(a, num, ref mx, ref mxIndex); //処理実行

            MessageBox.Show("Max = " + mx.ToString() + ", MaxIndex=" + mxIndex.ToString());

            Environment.Exit(0);
        }
    }
}
