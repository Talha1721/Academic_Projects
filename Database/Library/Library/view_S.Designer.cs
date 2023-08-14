namespace Library
{
    partial class viewStudent
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.StudentInfoPanel = new System.Windows.Forms.Panel();
            this.hall = new System.Windows.Forms.ComboBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.label11 = new System.Windows.Forms.Label();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.button6 = new System.Windows.Forms.Button();
            this.textbox_Name = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.button5 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.textBox_Student_ID = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.StuUPDATEPANEL = new System.Windows.Forms.Panel();
            this.Update = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.StudentInfoPanel.SuspendLayout();
            this.panel2.SuspendLayout();
            this.StuUPDATEPANEL.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.HotTrack;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(489, 3);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView1.Size = new System.Drawing.Size(1468, 743);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // StudentInfoPanel
            // 
            this.StudentInfoPanel.BackColor = System.Drawing.Color.Silver;
            this.StudentInfoPanel.Controls.Add(this.hall);
            this.StudentInfoPanel.Controls.Add(this.comboBox1);
            this.StudentInfoPanel.Controls.Add(this.dateTimePicker1);
            this.StudentInfoPanel.Controls.Add(this.label11);
            this.StudentInfoPanel.Controls.Add(this.textBox9);
            this.StudentInfoPanel.Controls.Add(this.label10);
            this.StudentInfoPanel.Controls.Add(this.textBox8);
            this.StudentInfoPanel.Controls.Add(this.textBox5);
            this.StudentInfoPanel.Controls.Add(this.textBox3);
            this.StudentInfoPanel.Controls.Add(this.textBox4);
            this.StudentInfoPanel.Controls.Add(this.textBox6);
            this.StudentInfoPanel.Controls.Add(this.label9);
            this.StudentInfoPanel.Controls.Add(this.label8);
            this.StudentInfoPanel.Controls.Add(this.label7);
            this.StudentInfoPanel.Controls.Add(this.label6);
            this.StudentInfoPanel.Controls.Add(this.label5);
            this.StudentInfoPanel.Controls.Add(this.label4);
            this.StudentInfoPanel.Controls.Add(this.label3);
            this.StudentInfoPanel.Controls.Add(this.label12);
            this.StudentInfoPanel.Location = new System.Drawing.Point(110, 752);
            this.StudentInfoPanel.Name = "StudentInfoPanel";
            this.StudentInfoPanel.Size = new System.Drawing.Size(1528, 291);
            this.StudentInfoPanel.TabIndex = 52;
            // 
            // hall
            // 
            this.hall.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hall.FormattingEnabled = true;
            this.hall.Items.AddRange(new object[] {
            "Khan Jahan Ali",
            "Khan Bahadur Ahsanullah",
            " Jatir Jonok Bongobondhu Sheikh Mujibur Rahman",
            "Aporijita",
            "Bongo Mata Sheikh Fojilatunnesa Mujib"});
            this.hall.Location = new System.Drawing.Point(194, 250);
            this.hall.Name = "hall";
            this.hall.Size = new System.Drawing.Size(355, 33);
            this.hall.TabIndex = 73;
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Architecture",
            "ECE",
            "CSE",
            "URP ",
            "Mathematics",
            "Physics",
            "Chemistry",
            "Statistics ",
            "Pharmacy",
            "BGE",
            "AT",
            "FMRT",
            "FWT",
            "SWE",
            "ES",
            "English",
            "Bangla",
            "History And Civilization",
            "BAD",
            "HRM",
            "Economics",
            "DS",
            "MCJ",
            "Sociology",
            "Law",
            "Drawing And Painting"});
            this.comboBox1.Location = new System.Drawing.Point(194, 140);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(251, 33);
            this.comboBox1.TabIndex = 72;
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.CustomFormat = "dd/MM/yy";
            this.dateTimePicker1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePicker1.Location = new System.Drawing.Point(1029, 75);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(149, 30);
            this.dateTimePicker1.TabIndex = 71;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(770, 189);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(77, 25);
            this.label11.TabIndex = 70;
            this.label11.Text = "EMAIL";
            // 
            // textBox9
            // 
            this.textBox9.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox9.Location = new System.Drawing.Point(1029, 184);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(307, 30);
            this.textBox9.TabIndex = 69;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(749, 126);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(157, 25);
            this.label10.TabIndex = 68;
            this.label10.Text = "CONTACT NO";
            // 
            // textBox8
            // 
            this.textBox8.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox8.Location = new System.Drawing.Point(1029, 123);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(245, 30);
            this.textBox8.TabIndex = 66;
            // 
            // textBox5
            // 
            this.textBox5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox5.Location = new System.Drawing.Point(1029, 33);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(171, 30);
            this.textBox5.TabIndex = 65;
            // 
            // textBox3
            // 
            this.textBox3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox3.Location = new System.Drawing.Point(194, 196);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(159, 30);
            this.textBox3.TabIndex = 64;
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox4.Location = new System.Drawing.Point(194, 93);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(399, 30);
            this.textBox4.TabIndex = 63;
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.textBox6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox6.Location = new System.Drawing.Point(194, 17);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(120, 30);
            this.textBox6.TabIndex = 62;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(749, 75);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(109, 25);
            this.label9.TabIndex = 61;
            this.label9.Text = "VALIDITY";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(10, 143);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(131, 25);
            this.label8.TabIndex = 60;
            this.label8.Text = "DISCIPLINE";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(829, 113);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(0, 25);
            this.label7.TabIndex = 59;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(737, 20);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(206, 25);
            this.label6.TabIndex = 58;
            this.label6.Text = "ACCADEMIC YEAR";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(10, 258);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(66, 25);
            this.label5.TabIndex = 57;
            this.label5.Text = "HALL";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(10, 199);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(110, 25);
            this.label4.TabIndex = 56;
            this.label4.Text = "CARD NO";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(3, 93);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(182, 25);
            this.label3.TabIndex = 55;
            this.label3.Text = "STUDENT NAME";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.BackColor = System.Drawing.Color.Gainsboro;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(3, 17);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(141, 25);
            this.label12.TabIndex = 54;
            this.label12.Text = "STUDENT ID";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Maroon;
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.button6);
            this.panel2.Controls.Add(this.textbox_Name);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.button5);
            this.panel2.Controls.Add(this.button4);
            this.panel2.Controls.Add(this.textBox_Student_ID);
            this.panel2.Controls.Add(this.button3);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Location = new System.Drawing.Point(12, 3);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(477, 720);
            this.panel2.TabIndex = 55;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // button6
            // 
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.Location = new System.Drawing.Point(379, 355);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(77, 40);
            this.button6.TabIndex = 28;
            this.button6.Text = "Go";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // textbox_Name
            // 
            this.textbox_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textbox_Name.Location = new System.Drawing.Point(-2, 289);
            this.textbox_Name.Name = "textbox_Name";
            this.textbox_Name.Size = new System.Drawing.Size(458, 38);
            this.textbox_Name.TabIndex = 27;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(179, 310);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 17);
            this.label2.TabIndex = 26;
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(3, 233);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(337, 50);
            this.button5.TabIndex = 25;
            this.button5.Text = "Student Name";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(379, 133);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(77, 40);
            this.button4.TabIndex = 24;
            this.button4.Text = "Go";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // textBox_Student_ID
            // 
            this.textBox_Student_ID.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_Student_ID.Location = new System.Drawing.Point(4, 80);
            this.textBox_Student_ID.Name = "textBox_Student_ID";
            this.textBox_Student_ID.Size = new System.Drawing.Size(452, 38);
            this.textBox_Student_ID.TabIndex = 23;
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(3, 23);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(361, 39);
            this.button3.TabIndex = 22;
            this.button3.Text = "Search  By  Student ID";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(179, 133);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 17);
            this.label1.TabIndex = 21;
            // 
            // StuUPDATEPANEL
            // 
            this.StuUPDATEPANEL.BackColor = System.Drawing.Color.Gray;
            this.StuUPDATEPANEL.Controls.Add(this.Update);
            this.StuUPDATEPANEL.Controls.Add(this.button1);
            this.StuUPDATEPANEL.Location = new System.Drawing.Point(1656, 761);
            this.StuUPDATEPANEL.Name = "StuUPDATEPANEL";
            this.StuUPDATEPANEL.Size = new System.Drawing.Size(242, 282);
            this.StuUPDATEPANEL.TabIndex = 56;
            // 
            // Update
            // 
            this.Update.BackColor = System.Drawing.SystemColors.ControlDark;
            this.Update.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Update.ForeColor = System.Drawing.SystemColors.Highlight;
            this.Update.Location = new System.Drawing.Point(27, 4);
            this.Update.Name = "Update";
            this.Update.Size = new System.Drawing.Size(188, 65);
            this.Update.TabIndex = 56;
            this.Update.Text = "Update";
            this.Update.UseVisualStyleBackColor = false;
            this.Update.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Teal;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button1.Location = new System.Drawing.Point(27, 114);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(179, 65);
            this.button1.TabIndex = 55;
            this.button1.Text = "Delete";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // viewStudent
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 1055);
            this.Controls.Add(this.StuUPDATEPANEL);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.StudentInfoPanel);
            this.Controls.Add(this.dataGridView1);
            this.Name = "viewStudent";
            this.Text = "Students";
            this.Load += new System.EventHandler(this.viewStudent_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.StudentInfoPanel.ResumeLayout(false);
            this.StudentInfoPanel.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.StuUPDATEPANEL.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Panel StudentInfoPanel;
        private System.Windows.Forms.ComboBox hall;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.TextBox textbox_Name;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox textBox_Student_ID;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel StuUPDATEPANEL;
        private System.Windows.Forms.Button Update;
        private System.Windows.Forms.Button button1;
    }
}