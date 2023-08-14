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
    public partial class viewStudent : Form
    {
        System.Data.SqlClient.SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");
        public viewStudent()
        {
            InitializeComponent();
        }

        private void viewStudent_Load(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From Student";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            
           
            int i;
            i = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "SELECT * FROM Student WHERE Serial= "+i+"";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                foreach(DataRow dr in dt.Rows)
                {

                    textBox6.Text = dr["StudentId"].ToString();
                    textBox4.Text= dr["StudentName"].ToString();
                    comboBox1.Text= dr["Discipline"].ToString();
                    textBox3.Text= dr["CardNo"].ToString();
                    hall.Text= dr["Hall"].ToString();
                    textBox5.Text= dr["AcademyYear"].ToString();
                    dateTimePicker1.Value=Convert.ToDateTime (dr["Validity"].ToString());//critical 
                    textBox8.Text= dr["ContactNo"].ToString();
                    textBox9.Text= dr["Email"].ToString();
                    conn.Close();
                }
              

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button4_Click(object sender, EventArgs e)
        {
            //Searching By Student ID
            

            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From Student Where StudentId =" + textBox_Student_ID.Text +"";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            // update student 
            int i;
            i = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
            try
            {
                conn.Open(); 
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "Update Student Set  StudentId='" + textBox6.Text + "',StudentName='" + textBox4.Text + "',Discipline='" + comboBox1.Text + "' ,CardNo='" + textBox3.Text + "',Hall='" + hall.Text + "',AcademyYear='" + textBox5.Text + "',Validity='" + dateTimePicker1.Value + "',Email='" + textBox9.Text + "'   WHERE Serial= " + i + "";
                cmd.ExecuteNonQuery();
                  conn.Close();
           
             
                    conn.Open();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = " Select* From Student";
                    cmd.ExecuteNonQuery();
                    DataTable dt = new DataTable();
                    SqlDataAdapter da = new SqlDataAdapter(cmd);
                    da.Fill(dt);
                    dataGridView1.DataSource = dt;
                    conn.Close();
                

                 MessageBox.Show("Update Successful");
             
            

               

               
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
             //Delete Button
            int i;
            i = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Delete  From Student WHERE Serial= " + i + "";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            StudentDataShow();
            TextBox_Clean();
            MessageBox.Show("Delete Record Successful");
        }

        public void StudentDataShow()
        {
            ////Data Grid View Code

            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From Student";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        public void TextBox_Clean()
        {
            textBox6.Text = "";
            textBox4.Text = "";
            comboBox1.Text = "";
            textBox3.Text = "";
            hall.Text = "";
            textBox5.Text = "";
            dateTimePicker1.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            conn.Close();

        }

        private void button6_Click(object sender, EventArgs e)
        {
            ////Search Student By Name

            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From Student Where StudentName Like ('%"+textbox_Name.Text+"%')";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }
    }

    }

