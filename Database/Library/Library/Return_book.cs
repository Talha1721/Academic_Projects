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
    public partial class Return_book : Form

    {
        System.Data.SqlClient.SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");
        public Return_book()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ///searching Id
            panel3.Visible = true;
            Fill_gid(txtbox_id.Text);

        }

        private void Return_book_Load(object sender, EventArgs e)
        {
            if(conn.State==ConnectionState.Open)
            {

                conn.Close();
            }
            conn.Open();
        }
        public void Fill_gid(string enrollment)
        {

            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "SELECT *FROM Issue_book WHERE StudentId='"+enrollment.ToString()+ "' AND ReturnDate=' '";
            //cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            dataGridView1.DataSource = dt;



        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            panel2.Visible = true;
            int i;
            i = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
            try
            {
            
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "SELECT * FROM  Issue_book WHERE Id= "+ i + "";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                foreach (DataRow dr in dt.Rows)
                {

                    label_book.Text= dr["BookTitle"].ToString();             
                    label_issuedate.Text = dr["IssueDate"].ToString();
                  
                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btn_return_Click(object sender, EventArgs e)
        {
            try
            {
                int i;
                i = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());

                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "Update  Issue_book SET ReturnDate='"+ dateTimePicker1 .Value.ToString()+ "'  WHERE Id= " + i + "";
                cmd.ExecuteNonQuery();

                //After Return the book decrese the taken book

                SqlCommand cmd2 = conn.CreateCommand();
                cmd2.CommandType = CommandType.Text;
                cmd2.CommandText = "Update Student Set TakenBook=TakenBook-1 Where StudentId= '" + txtbox_id.Text + "'";
                cmd2.ExecuteNonQuery();
                //////// 
                //Update Grid view after returning the book     
                Fill_gid(txtbox_id.Text);



                ///



                MessageBox.Show("Return Operation is Successful");



            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }
    }
}
