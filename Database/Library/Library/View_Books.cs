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
    public partial class View_Bookss : Form
    {

        System.Data.SqlClient.SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;"); public View_Bookss()
        {
            InitializeComponent();
        }

        private void View_Student_Load(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From book_tabler";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView2.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            int i;
            i = Convert.ToInt32(dataGridView2.SelectedCells[0].Value.ToString());
            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "SELECT * FROM book_tabler WHERE Serial= " + i + "";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                foreach (DataRow dr in dt.Rows)
                {
                    text_accn.Text = dr["Accno"].ToString();
                    txt_booktitle.Text = dr["BookTitle"].ToString();
                    txt_author.Text = dr["Author"].ToString();
                    txt_publisher.Text = dr["Publisher"].ToString();
                    txt_edition.Text = dr["Edition"].ToString();
                    txt_accn_date.Value = Convert.ToDateTime(dr["AccnDate"].ToString());//critical 
                    txt_isbn.Text = dr["Isbn"].ToString();
                    txt_callno.Text = dr["CallNo"].ToString();
                    txt_price.Text = dr["price"].ToString();
                    conn.Close();  
                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Update_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are You Sure To Update", "Update", MessageBoxButtons.YesNo);
            if (result == DialogResult.Yes)
            {
                int i;
                i = Convert.ToInt32(dataGridView2.SelectedCells[0].Value.ToString());
                try
                {
                    conn.Open();
                    SqlCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = "Update book_tabler Set Accno='" + text_accn.Text + "',BookTitle='" + txt_booktitle.Text + "',Author='" + txt_author.Text + "' ,Publisher='" + txt_publisher.Text + "',Edition='" + txt_edition.Text + "',AccnDate='" + txt_accn_date.Value + "',Isbn='" + txt_isbn.Text + "',CallNo='" + txt_callno.Text + "',price='" + txt_price.Text + "'   WHERE Serial= " + i + "";
                    cmd.ExecuteNonQuery();
                    conn.Close();


                    conn.Open();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = " Select* From Student";
                    cmd.ExecuteNonQuery();
                    DataTable dt = new DataTable();
                    SqlDataAdapter da = new SqlDataAdapter(cmd);
                    da.Fill(dt);
                    dataGridView2.DataSource = dt;
                    conn.Close();
                    Bookdata_show();

                    MessageBox.Show("Update Successful");

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }
        public void Bookdata_show()
        {

            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From book_tabler";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView2.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button4_Click(object sender, EventArgs e)
        {
            //Searching By Athur


            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From book_tabler Where Author Like ('%" + Searchby_author.Text + "%')";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView2.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button6_Click(object sender, EventArgs e)
        {
            //Searching By Book_Name


            try
            {
                conn.Open();
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = " Select* From book_tabler Where BookTitle Like ('%" + textbox_Book_name.Text + "%')";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView2.DataSource = dt;
                conn.Close();
            }

            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Delete Button
            DialogResult result = MessageBox.Show("Are You Sure To Delete", "Delete", MessageBoxButtons.YesNo);
            if (result == DialogResult.Yes)
            {
                int i;
                i = Convert.ToInt32(dataGridView2.SelectedCells[0].Value.ToString());
                try
                {
                    conn.Open();
                    SqlCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = " Delete  From book_tabler WHERE Serial= " + i + "";
                    cmd.ExecuteNonQuery();
                    DataTable dt = new DataTable();
                    SqlDataAdapter da = new SqlDataAdapter(cmd);
                    da.Fill(dt);
                    dataGridView2.DataSource = dt;
                    conn.Close();
                    Bookdata_show();
                }

                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }


                MessageBox.Show("Delete Record Successful");
            }
        }
    }
}
