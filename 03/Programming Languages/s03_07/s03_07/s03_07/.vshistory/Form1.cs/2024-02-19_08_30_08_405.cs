namespace s03_07
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.Click += new System.EventHandler(Button1_Click);
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            string Rstr;
            if (textBox2.Text == "0" && comboBox1.SelectedIndex == 3)
            {
                Rstr = "Невозможно делить на 0!";
                textBox3.Text = Rstr;
                return;
            }
            else
                Rstr = ResultHandler();
            if (!checkBox1.Checked)
                textBox3.Text = Rstr;
            else
            {
                string RES = Convert.ToString(textBox1.Text)
                + comboBox1.Text[0]
                + Convert.ToString(textBox2.Text)
                + "="
                + Rstr;
                textBox3.Text = RES;
            }
        }
        private void Button1_DClick(object sender, EventArgs e)
        {
            string Rstr = ResultHandler();
            string RES = Convert.ToString(textBox1.Text)
                + comboBox1.Text[0]
                + Convert.ToString(textBox2.Text)
                + "="
                + Rstr;
            textBox3.Text = RES;
        }
        private string ResultHandler()
        {
            double a = Convert.ToDouble(textBox1.Text),
                b = Convert.ToDouble(textBox2.Text), res = 0;
            int mode = comboBox1.SelectedIndex;
            switch (mode)
            {
                case 0: res = a + b; break;
                case 1: res = a * b; break;
                case 2: res = a - b; break;
                case 3: if (b != 0) res = a / b; break;
                default: break;
            }
            return Convert.ToString(res);
        }
    }
}
