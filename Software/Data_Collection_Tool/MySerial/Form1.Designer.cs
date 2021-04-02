namespace MySerial
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.portBox = new System.Windows.Forms.ComboBox();
            this.rateBox = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.refresh = new System.Windows.Forms.Button();
            this.open = new System.Windows.Forms.Button();
            this.log = new System.Windows.Forms.Button();
            this.clear = new System.Windows.Forms.Button();
            this.serialBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // portBox
            // 
            this.portBox.FormattingEnabled = true;
            this.portBox.Location = new System.Drawing.Point(97, 12);
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(121, 23);
            this.portBox.TabIndex = 0;
            // 
            // rateBox
            // 
            this.rateBox.FormattingEnabled = true;
            this.rateBox.Location = new System.Drawing.Point(97, 61);
            this.rateBox.Name = "rateBox";
            this.rateBox.Size = new System.Drawing.Size(121, 23);
            this.rateBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(52, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "Port";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 69);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(79, 15);
            this.label2.TabIndex = 3;
            this.label2.Text = "Baud Rate";
            // 
            // refresh
            // 
            this.refresh.Location = new System.Drawing.Point(246, 61);
            this.refresh.Name = "refresh";
            this.refresh.Size = new System.Drawing.Size(75, 32);
            this.refresh.TabIndex = 4;
            this.refresh.Text = "Refresh";
            this.refresh.UseVisualStyleBackColor = true;
            this.refresh.Click += new System.EventHandler(this.refresh_Click);
            // 
            // open
            // 
            this.open.Location = new System.Drawing.Point(246, 11);
            this.open.Name = "open";
            this.open.Size = new System.Drawing.Size(75, 33);
            this.open.TabIndex = 5;
            this.open.Text = "Open";
            this.open.UseVisualStyleBackColor = true;
            this.open.Click += new System.EventHandler(this.open_Click);
            // 
            // log
            // 
            this.log.Location = new System.Drawing.Point(695, 60);
            this.log.Name = "log";
            this.log.Size = new System.Drawing.Size(75, 33);
            this.log.TabIndex = 6;
            this.log.Text = "Log";
            this.log.UseVisualStyleBackColor = true;
            this.log.Click += new System.EventHandler(this.log_Click);
            // 
            // clear
            // 
            this.clear.Location = new System.Drawing.Point(695, 12);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(75, 32);
            this.clear.TabIndex = 7;
            this.clear.Text = "Clear";
            this.clear.UseVisualStyleBackColor = true;
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // serialBox
            // 
            this.serialBox.Location = new System.Drawing.Point(15, 126);
            this.serialBox.Multiline = true;
            this.serialBox.Name = "serialBox";
            this.serialBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.serialBox.Size = new System.Drawing.Size(755, 300);
            this.serialBox.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(787, 450);
            this.Controls.Add(this.serialBox);
            this.Controls.Add(this.clear);
            this.Controls.Add(this.log);
            this.Controls.Add(this.open);
            this.Controls.Add(this.refresh);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.rateBox);
            this.Controls.Add(this.portBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "My Serial";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox portBox;
        private System.Windows.Forms.ComboBox rateBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button refresh;
        private System.Windows.Forms.Button open;
        private System.Windows.Forms.Button log;
        private System.Windows.Forms.Button clear;
        private System.Windows.Forms.TextBox serialBox;
    }
}

