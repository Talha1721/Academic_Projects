using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Library
{
    public partial class bookreg : Form
    {
        SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");
        public bookreg()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            //Cheaking Duplicate ACCN No of Book 
            SqlDataAdapter sda = new SqlDataAdapter("SELECT count(*) FROM book_tabler WHERE Accno='" + textBox1.Text + "'", conn);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            if (dt.Rows[0][0].ToString() == "0")//if no match so insert 
            {
                try
                {
                    conn.Open();
                    SqlCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = "Insert INTO book_tabler values('" + textBox1.Text + "','" + dateTimePicker2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "','" + textBox7.Text + "'," + textBox8.Text + ",'" + textBox9.Text + "')";
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Successfully added");
                    conn.Close();
                }
                catch (Exception ex)
                {
                    {
                        MessageBox.Show(ex.Message);
                    }
                }
        }
            else
            {
                MessageBox.Show("This ACCN is Duplicate");
            }
          
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
