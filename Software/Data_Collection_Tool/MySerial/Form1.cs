using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
//using CsvHelper;
//using Microsoft.WindowsAPICodePack.Shell;
using System.IO;

namespace MySerial
{
    public partial class Form1 : Form
    {
        private static SerialPort mySer;
        private static bool openFlag = false;
        private Thread serThread;
        private delegate void myDelObj(object obj);//The delegate object
        public Form1()
        {
            InitializeComponent();
            //Initialisation
            this.refreshPort();
            this.refreshRate();
            //serialBox.Text = "test\r\ntest";
            
        }
        private void refreshPort() //This method will reload the ports
        {
            this.portBox.Items.Clear();
            foreach (string portItem in SerialPort.GetPortNames())
            {
                this.portBox.Items.Add(portItem);
            }
        }
        private void refreshRate() //This method is used for initialisation
        {
            this.rateBox.Items.Add("9600");
            this.rateBox.Items.Add("38400");
            this.rateBox.Items.Add("115200");
        }

        private void refresh_Click(object sender, EventArgs e) //The function of refresh button
        {
            this.refreshPort();
        }

        private void open_Click(object sender, EventArgs e) //Open the serial port
        {

            if (openFlag == false)
            {
                try
                {
                    serThread = new Thread(new ParameterizedThreadStart(serialRead)); //set the thread
                    mySer = new SerialPort(); //Set the serial port
                    mySer.PortName = portBox.Text;
                    mySer.BaudRate = Convert.ToInt32(rateBox.Text);
                    mySer.Open(); //Open the serial port
                    serThread.Start(); //Start a new thread
                    openFlag = true; //The flag will be set as true
                    open.Text = "Close"; 
                }
                catch(Exception exc)
                {
                    MessageBox.Show(exc.Message);
                }
            }
            else
            {
                try
                {
                    mySer.Close(); //Close the serial port
                    openFlag = false; //flag to false
                    open.Text = "Open";
                    //serThread.Join();
                }
                catch(Exception exc)
                {
                    MessageBox.Show(exc.Message);
                }
            }

        }
        private void serialRead(object obj) //Serial port thread
        {
            myDelObj delObj = new myDelObj(serialReadUpdate);
            while (openFlag)
            {
                try
                {
                    string readString = mySer.ReadExisting();
                    delObj.Invoke(readString); //update the string to the text box
                }
                catch(Exception exc)
                {
                    MessageBox.Show(exc.Message + "An unknown error!");
                }
            }
        }
        private void serialReadUpdate(object content) //text box updating
        {
            
            if (InvokeRequired)
            {
                myDelObj method = new myDelObj(serialReadUpdate);
                Invoke(method, content);
                return;
            }
            
            serialBox.Text += (string)content;
            serialBox.SelectionStart = serialBox.Text.Length;
            serialBox.ScrollToCaret();
        }

        private void clear_Click(object sender, EventArgs e) //Clear the text box
        {
            serialBox.Text = "";
        }

        private void log_Click(object sender, EventArgs e)
        {
            try
            {
                SaveFileDialog savefiledialog = new SaveFileDialog();

                string filter = "CSV file (*.csv)|*.csv| All Files (*.*)|*.*";
                savefiledialog.Filter = filter;
                savefiledialog.FileName = "fingerdata";
                savefiledialog.DefaultExt = "csv";
                savefiledialog.AddExtension = true;//auto extension
                //string savePath;
                if (savefiledialog.ShowDialog() == DialogResult.OK)
                {
                    using (StreamWriter sw = new StreamWriter(savefiledialog.FileName))
                    {
                        sw.WriteLine(serialBox.Text);
                        sw.Close();
                    }
                }
                MessageBox.Show("File Saved");
            }
            catch (Exception exc)
            {
                    MessageBox.Show(exc.Message + "An unknown error!");
            }
            
        }
    }
}
