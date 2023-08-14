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
    public partial class stdentry : Form
    {
        SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");
        public stdentry()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            

        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            
        }

        private void stdentry_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {

            //Cheaking Duplicate Student Id
            SqlDataAdapter sda = new SqlDataAdapter("SELECT count(*) FROM Student WHERE StudentId='" + textBox1.Text + "'", conn);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            if (dt.Rows[0][0].ToString() == "0")//if no match so insert 
            {

                try

                {
                    conn.Open();
                    SqlCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = "INSERT INTO Student values('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + hall.Text + "','" + textBox5.Text + "','" + comboBox1.Text + "','" + dateTimePicker1.Text + "','" + textBox8.Text + "','" + textBox9.Text + "','" + 0 + "')";
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Successfully added");

                    conn.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }


            }
            else//if match so, give the message that id is existing 
            {
                MessageBox.Show("This Entity Already Existing");
            }

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
 