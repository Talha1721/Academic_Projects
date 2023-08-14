using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Library
{
    public partial class manageForm : Form
    {
        public manageForm()
        {
            InitializeComponent();
        }

        private void manageForm_Load(object sender, EventArgs e)
        {

        }

        private void entryBooksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bookreg obj = new bookreg();
            obj.Show();
        }

        private void entrySudentsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            stdentry obj = new stdentry();       
            obj.Show();
        }

        private void issueBookToolStripMenuItem_Click(object sender, EventArgs e)
        {
            issue_form obj = new issue_form();
            obj.Show();
        }

        private void viewBooksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            View_Bookss book = new View_Bookss();
            book.Show();
        }

        private void viewStudentToolStripMenuItem_Click(object sender, EventArgs e)
        {
            viewStudent std = new viewStudent();
            std.Show();


        }

        private void manageForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //main prog cancel korbo kina setar code
            DialogResult result = MessageBox.Show("Are You Sure To Exit The Program", "Exit", MessageBoxButtons.YesNo,MessageBoxIcon.Question);
            if(result==DialogResult.Yes)
            {
               
                Application.Exit();


            }
            else
            {
                e.Cancel = true;
            }
        }

        private void returnBookToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void issueBooksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            issue_form obj = new issue_form();
            obj.Show();
        }

        private void returnBookToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Return_book rbook = new Return_book();
            rbook.Show();
        }
    }
}
