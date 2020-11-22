using System;
using System.Windows.Forms;
using Wrapper;

namespace CsMainUser
{
    public partial class Form1 : Form
    {
        WrapperClass _wr = new WrapperClass();
        public Form1()
        {
            InitializeComponent();

            int[] data = { 1, 3, 5, 99, 4};
            int max = 0;
            int maxIndex = 0;
            int num = data.Length;

            _wr.Max(data, num, ref max, ref maxIndex);
            Console.WriteLine($"Length= {num}, Max= {max}, MaxIndex= {maxIndex}");

            _wr.ImageProcess();
        }
    }
}
