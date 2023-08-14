namespace Library
{
    partial class manageForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(manageForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.bookToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewBooksToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.entryBooksToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.studentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewStudentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.entrySudentsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.passwordToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.changePasswordToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.issueBooksToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.returnBookToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bookToolStripMenuItem,
            this.studentToolStripMenuItem,
            this.toolStripMenuItem1,
            this.helpToolStripMenuItem,
            this.passwordToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1840, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // bookToolStripMenuItem
            // 
            this.bookToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.viewBooksToolStripMenuItem,
            this.entryBooksToolStripMenuItem,
            this.issueBooksToolStripMenuItem,
            this.returnBookToolStripMenuItem1});
            this.bookToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("bookToolStripMenuItem.Image")));
            this.bookToolStripMenuItem.Name = "bookToolStripMenuItem";
            this.bookToolStripMenuItem.Size = new System.Drawing.Size(75, 24);
            this.bookToolStripMenuItem.Text = "Book";
            // 
            // viewBooksToolStripMenuItem
            // 
            this.viewBooksToolStripMenuItem.Image = global::Library.Properties.Resources.book_entry;
            this.viewBooksToolStripMenuItem.Name = "viewBooksToolStripMenuItem";
            this.viewBooksToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.viewBooksToolStripMenuItem.Text = "view books";
            this.viewBooksToolStripMenuItem.Click += new System.EventHandler(this.viewBooksToolStripMenuItem_Click);
            // 
            // entryBooksToolStripMenuItem
            // 
            this.entryBooksToolStripMenuItem.Image = global::Library.Properties.Resources.book_entry;
            this.entryBooksToolStripMenuItem.Name = "entryBooksToolStripMenuItem";
            this.entryBooksToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.entryBooksToolStripMenuItem.Text = "Entry Books";
            this.entryBooksToolStripMenuItem.Click += new System.EventHandler(this.entryBooksToolStripMenuItem_Click);
            // 
            // studentToolStripMenuItem
            // 
            this.studentToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.viewStudentToolStripMenuItem,
            this.entrySudentsToolStripMenuItem});
            this.studentToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("studentToolStripMenuItem.Image")));
            this.studentToolStripMenuItem.Name = "studentToolStripMenuItem";
            this.studentToolStripMenuItem.Size = new System.Drawing.Size(92, 24);
            this.studentToolStripMenuItem.Text = "Student";
            // 
            // viewStudentToolStripMenuItem
            // 
            this.viewStudentToolStripMenuItem.Name = "viewStudentToolStripMenuItem";
            this.viewStudentToolStripMenuItem.Size = new System.Drawing.Size(173, 26);
            this.viewStudentToolStripMenuItem.Text = "View student";
            this.viewStudentToolStripMenuItem.Click += new System.EventHandler(this.viewStudentToolStripMenuItem_Click);
            // 
            // entrySudentsToolStripMenuItem
            // 
            this.entrySudentsToolStripMenuItem.Name = "entrySudentsToolStripMenuItem";
            this.entrySudentsToolStripMenuItem.Size = new System.Drawing.Size(173, 26);
            this.entrySudentsToolStripMenuItem.Text = "Entry Sudents";
            this.entrySudentsToolStripMenuItem.Click += new System.EventHandler(this.entrySudentsToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(33, 24);
            this.toolStripMenuItem1.Text = "   ";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Image = global::Library.Properties.Resources.help;
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(73, 24);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // passwordToolStripMenuItem
            // 
            this.passwordToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.changePasswordToolStripMenuItem1});
            this.passwordToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("passwordToolStripMenuItem.Image")));
            this.passwordToolStripMenuItem.Name = "passwordToolStripMenuItem";
            this.passwordToolStripMenuItem.Size = new System.Drawing.Size(102, 24);
            this.passwordToolStripMenuItem.Text = "Password";
            // 
            // changePasswordToolStripMenuItem1
            // 
            this.changePasswordToolStripMenuItem1.Name = "changePasswordToolStripMenuItem1";
            this.changePasswordToolStripMenuItem1.Size = new System.Drawing.Size(201, 26);
            this.changePasswordToolStripMenuItem1.Text = "Change password";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 72F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Purple;
            this.label1.Location = new System.Drawing.Point(-17, 488);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(1845, 135);
            this.label1.TabIndex = 1;
            this.label1.Text = "Khulna University Central Library";
            // 
            // issueBooksToolStripMenuItem
            // 
            this.issueBooksToolStripMenuItem.Name = "issueBooksToolStripMenuItem";
            this.issueBooksToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.issueBooksToolStripMenuItem.Text = "Issue Books";
            this.issueBooksToolStripMenuItem.Click += new System.EventHandler(this.issueBooksToolStripMenuItem_Click);
            // 
            // returnBookToolStripMenuItem1
            // 
            this.returnBookToolStripMenuItem1.Name = "returnBookToolStripMenuItem1";
            this.returnBookToolStripMenuItem1.Size = new System.Drawing.Size(216, 26);
            this.returnBookToolStripMenuItem1.Text = "Return Book";
            this.returnBookToolStripMenuItem1.Click += new System.EventHandler(this.returnBookToolStripMenuItem1_Click);
            // 
            // manageForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1840, 649);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.Cursor = System.Windows.Forms.Cursors.Hand;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "manageForm";
            this.Text = "Library Management";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.manageForm_FormClosing);
            this.Load += new System.EventHandler(this.manageForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem bookToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewBooksToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem studentToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewStudentToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem passwordToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem entryBooksToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem entrySudentsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem changePasswordToolStripMenuItem1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripMenuItem issueBooksToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem returnBookToolStripMenuItem1;
    }
}