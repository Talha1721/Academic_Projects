using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Library
{
    public partial class LogIn : Form
    {
        SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-RGA8UK6\RASEL;Initial Catalog=Libray_system;Integrated Security=True;");
        public LogIn()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlDataAdapter sda=new SqlDataAdapter("SELECT count(*) FROM LogIn WHERE UserName='"+tbox11.Text+ "' AND Password='"+tbox12.Text+"'", conn);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            if(dt.Rows[0][0].ToString()=="1")
            {
                this.Hide();
                manageForm obj = new manageForm();
                obj.Show();

            }
            else
            {
                MessageBox.Show("Enter Valid User Name and Password");
            }
 
        }

        private void LogIn_Load(object sender, EventArgs e)
        {
           



        }
    }
}
