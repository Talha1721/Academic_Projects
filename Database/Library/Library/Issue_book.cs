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
    public partial class issue_form : Form
    {
        SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");

        public issue_form()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            if(conn.State==ConnectionState.Open)
            {
                conn.Close();
            }
            conn.Open();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {



            int i = 0;
            int j = 0;
            try
            {
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "Select * From Student Where StudentId='" + txtbox_stuId.Text + "' ";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                i = Convert.ToInt32(dt.Rows.Count.ToString());
                if (i == 0)
                {
                    MessageBox.Show("This Student Yet Not Registered");

                }

                else
                {


                    SqlCommand cmd1 = conn.CreateCommand();
                    cmd1.CommandType = CommandType.Text;
                    cmd1.CommandText = "Select * From Student Where StudentId='" + txtbox_stuId.Text + "' ";
                    cmd1.ExecuteNonQuery();
                    DataTable dt1 = new DataTable();
                    SqlDataAdapter da1 = new SqlDataAdapter(cmd1);
                    da1.Fill(dt1 );
                  foreach(DataRow dr2 in dt1.Rows )
                    {
                        j = Convert.ToInt32(dr2["TakenBook"].ToString());
                    }
                    if (j <3)//if student take less than 3 book;
                    {




                        foreach (DataRow dr in dt.Rows)
                        {
                            textBoxStudentname.Text = dr["StudentName"].ToString();
                            textBoxContact.Text = dr["ContactNo"].ToString();
                            textBoxEmail.Text = dr["Email"].ToString();
                            textBoxDiscipline.Text = dr["Discipline"].ToString();

                        }
                    }
                    else
                    {
                        MessageBox.Show("This Student already have  Taken Limited Number Books");
                    }

                }


            }
            catch(Exception ex)
            {

                MessageBox.Show(ex.Message);
            }
        }

        private void Issue_date_ValueChanged(object sender, EventArgs e)
        {

        }

        private void txtboxBooktitle_KeyUp(object sender, KeyEventArgs e)
        {
            int count = 0;
            if(e.KeyCode!=Keys.Enter)
            {

                listBox1.Items.Clear();

                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "Select * From book_tabler Where BookTitle Like('%" + txtboxBooktitle.Text + "%')";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                count=Convert.ToInt32(dt.Rows.Count.ToString());
                if(count>0)
                {
                    listBox1.Visible = true;
                    foreach(DataRow dr in dt.Rows)
                    {

                        listBox1.Items.Add(dr["BookTitle"].ToString());
                    }

                }

            }
             
        }

        private void txtboxBooktitle_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode==Keys.Down)
            {
                listBox1.Focus();
                listBox1.SelectedIndex = 0;
            }
        }

        private void listBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode==Keys.Enter)
            {

                txtboxBooktitle.Text = listBox1.SelectedItem.ToString();
                listBox1.Visible = false;
            }
        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            txtboxBooktitle.Text = listBox1.SelectedItem.ToString();
            listBox1.Visible = false;
        }

        private void Issu_book_bbtn_Click(object sender, EventArgs e)
        {
            int j = 0;
            //Cheaking if cross the limitation 
            SqlCommand cmd1 = conn.CreateCommand();
            cmd1.CommandType = CommandType.Text;
            cmd1.CommandText = "Select * From Student Where StudentId='" + txtbox_stuId.Text + "' ";
            cmd1.ExecuteNonQuery();
            DataTable dt1 = new DataTable();
            SqlDataAdapter da1 = new SqlDataAdapter(cmd1);
            da1.Fill(dt1);
            foreach (DataRow dr2 in dt1.Rows)
            {
                j = Convert.ToInt32(dr2["TakenBook"].ToString());
            }
            if (j < 3)//if student take less than 3 book;
            {

                try
                {
                    SqlCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = "Insert INTO Issue_book values('" + txtbox_stuId.Text + "','" + textBoxStudentname.Text + "','" + textBoxContact.Text + "','" + textBoxEmail.Text + "','" + textBoxDiscipline.Text + "','" + txtboxBooktitle.Text + "','" + txt_date.Text + "','')";
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Successfully added");
                    ; ///// After iSssue Update Taken Book

                    SqlCommand cmd2 = conn.CreateCommand();
                    cmd2.CommandType = CommandType.Text;
                    cmd2.CommandText = "Update Student Set TakenBook=TakenBook+1 Where StudentId= '" + txtbox_stuId.Text + "'";
                    cmd2.ExecuteNonQuery();
                    ;//////// finish update



                }
                catch (Exception ex)
                {

                    MessageBox.Show(ex.Message);
                }
            }
            else
            {
                MessageBox.Show("This Student already have  Taken Limited Number Books");
            }

        }

        private void textBoxStudentname_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtboxBooktitle_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
