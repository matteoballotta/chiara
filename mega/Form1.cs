using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mega
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        int x = 0, n = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            string s = textBox1.Text;
            if (x==10)
            {
                richTextBox1.Text += "Saluti finiti :(";
                button1.Enabled = false;
                return;
            }
            if (checkBox1.Checked)
            {
                int i=1;
                if (x > 5) i = 10 - x;
                for (int j=i; j <= 5; j++)
                {
                    richTextBox1.Text += "Ciao " + s + "\n";
                    x++;
                }
                n += 5;
            }
            else
            {
                richTextBox1.Text += "Ciao " + s + "\n";
                x++;
                n++;
            }
            if (n > 10)
            {
                richTextBox1.Text += "Hai provato troppe volte! \n";
                x = 10;
            }
            progressBar1.Value = x;
            label2.Text = "Saluti: " + x + "/10";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
