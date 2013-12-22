#pragma once

using namespace System;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO ;
using namespace System::Drawing ::Printing ;
using namespace System::Drawing;
#include "SearchForm1.h"
#include "ReplaceForm.h"
#include  "AboutForm.h"
#include "ToForm1.h"
#include <cliext/vector>
#include <cliext/map>
#using <system.dll>
using namespace cliext;



namespace WordPad {

	/// <summary>
	/// MainForm ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			System::IO ::StreamReader^ reader = gcnew System::IO::StreamReader ("step.txt",System::Text::Encoding ::Default );
			while (!reader->EndOfStream)
			{
				String^ sentense = reader->ReadLine();
				array<String^>^ seperation = gcnew array<String^>{"~~"};
				array<String^>^ result = sentense->Split(seperation,2,StringSplitOptions::RemoveEmptyEntries);
				if(result->Length >= 1)
				{
					if(result->Length >= 2)
						m_MDatabase[result[0]] = result[1];
					else
						m_MDatabase[result[0]] = "";
				}
				else
					continue;			
			}
			m_nIndex = -1;
			m_bNeedProcessTextChanged = true;
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemFile;

	private: System::Windows::Forms::ToolStripMenuItem^  menuItemNew;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemOpen;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemSave;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemSaveAs;







	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemPageSetup;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemPrint;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemExit;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemEdit;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemUndo;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemCut;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemCopy;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemStick;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemDel;





	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemFind;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemFindNext;


	private: System::Windows::Forms::ToolStripMenuItem^  menuItemReplace;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemTo;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemSelectAll;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemDayTime;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemFormat;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemWrap;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemfFont;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemView;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemState;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemAboutTopic;
	private: System::Windows::Forms::ToolStripMenuItem^  menuItemAbout;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::TextBox^  txtBoxMain;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PageSetupDialog^  pageSetupDialog1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnNew;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnOpen;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnSave;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnPrint;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnCut;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnCopy;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnPaster;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnBold;








	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnItalic;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnUnderline;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ճ��VToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ɾ��DelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  ȫѡAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem6;

	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripButton^  tlsbtnColor;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox2;
	private: System::Windows::Forms::ListBox^  TipBox;



	private: System::ComponentModel::IContainer^  components;








	protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		map<String^,String^> m_MDatabase;
		vector<String^> m_VExpalantion;
		int m_nIndex;		//��¼��ʼʶ���λ��
		bool m_bNeedProcessTextChanged;	//����Ƿ���ҪtextChanged�¼�����
		static int m_snCharsPerLine = 20;
		static int WM_HSCROLL = 276;
		static int SB_LEFT = 6;
		static int SB_RIGHT = 7;
		static int SB_PAGELEFT = 2;
		static int SB_PAGERIGHT = 3;
		[DllImport("user32.dll", CharSet = CharSet::Auto, SetLastError = false)]
		static int SendMessage(IntPtr hWnd, int wMsg, IntPtr wParam, IntPtr lParam);

	private: System::Windows::Forms::ToolTip^  toolTip;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// �����֧������ķ��� - ��Ҫ
			 /// ʹ�ô���༭���޸Ĵ˷��������ݡ�
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->menuItemFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemSaveAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->menuItemPageSetup = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemPrint = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->menuItemExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemEdit = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemUndo = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemCut = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemStick = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemDel = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->menuItemFind = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemFindNext = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemReplace = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemTo = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->menuItemSelectAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemDayTime = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemFormat = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemWrap = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemfFont = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemView = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemState = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemAboutTopic = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->menuItemAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
				 this->toolStripComboBox2 = (gcnew System::Windows::Forms::ToolStripComboBox());
				 this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
				 this->tlsbtnNew = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnOpen = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnSave = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnPrint = (gcnew System::Windows::Forms::ToolStripButton());
				 this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->tlsbtnCut = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnCopy = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnPaster = (gcnew System::Windows::Forms::ToolStripButton());
				 this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->tlsbtnBold = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnItalic = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnUnderline = (gcnew System::Windows::Forms::ToolStripButton());
				 this->tlsbtnColor = (gcnew System::Windows::Forms::ToolStripButton());
				 this->txtBoxMain = (gcnew System::Windows::Forms::TextBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				 this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
				 this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
				 this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
				 this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->����CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->ճ��VToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->ɾ��DelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->ȫѡAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
				 this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
				 this->TipBox = (gcnew System::Windows::Forms::ListBox());
				 this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
				 this->menuStrip1->SuspendLayout();
				 this->toolStrip1->SuspendLayout();
				 this->contextMenuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->menuItemFile, this->menuItemEdit, 
					 this->menuItemFormat, this->menuItemView, this->menuItemHelp, this->toolStripComboBox1, this->toolStripComboBox2});
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(788, 29);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // menuItemFile
				 // 
				 this->menuItemFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->menuItemNew, 
					 this->menuItemOpen, this->menuItemSave, this->menuItemSaveAs, this->toolStripMenuItem1, this->menuItemPageSetup, this->menuItemPrint, 
					 this->toolStripMenuItem2, this->menuItemExit});
				 this->menuItemFile->Name = L"menuItemFile";
				 this->menuItemFile->Size = System::Drawing::Size(74, 25);
				 this->menuItemFile->Text = L"�ļ���&F��";
				 // 
				 // menuItemNew
				 // 
				 this->menuItemNew->Name = L"menuItemNew";
				 this->menuItemNew->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
				 this->menuItemNew->Size = System::Drawing::Size(181, 22);
				 this->menuItemNew->Text = L"�½���&N��";
				 this->menuItemNew->Click += gcnew System::EventHandler(this, &MainForm::menuItemNew_Click);
				 // 
				 // menuItemOpen
				 // 
				 this->menuItemOpen->Name = L"menuItemOpen";
				 this->menuItemOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
				 this->menuItemOpen->Size = System::Drawing::Size(181, 22);
				 this->menuItemOpen->Text = L"�򿪣�&O��";
				 this->menuItemOpen->Click += gcnew System::EventHandler(this, &MainForm::menuItemOpen_Click);
				 // 
				 // menuItemSave
				 // 
				 this->menuItemSave->Name = L"menuItemSave";
				 this->menuItemSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
				 this->menuItemSave->Size = System::Drawing::Size(181, 22);
				 this->menuItemSave->Text = L"���棨&S��";
				 this->menuItemSave->Click += gcnew System::EventHandler(this, &MainForm::menuItemSave_Click);
				 // 
				 // menuItemSaveAs
				 // 
				 this->menuItemSaveAs->Name = L"menuItemSaveAs";
				 this->menuItemSaveAs->Size = System::Drawing::Size(181, 22);
				 this->menuItemSaveAs->Text = L"���Ϊ��&A��...";
				 this->menuItemSaveAs->Click += gcnew System::EventHandler(this, &MainForm::menuItemSaveAs_Click);
				 // 
				 // toolStripMenuItem1
				 // 
				 this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				 this->toolStripMenuItem1->Size = System::Drawing::Size(178, 6);
				 // 
				 // menuItemPageSetup
				 // 
				 this->menuItemPageSetup->Name = L"menuItemPageSetup";
				 this->menuItemPageSetup->Size = System::Drawing::Size(181, 22);
				 this->menuItemPageSetup->Text = L"ҳ�����ã�&U��...";
				 this->menuItemPageSetup->Click += gcnew System::EventHandler(this, &MainForm::menuItemPageSetup_Click);
				 // 
				 // menuItemPrint
				 // 
				 this->menuItemPrint->Name = L"menuItemPrint";
				 this->menuItemPrint->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
				 this->menuItemPrint->Size = System::Drawing::Size(181, 22);
				 this->menuItemPrint->Text = L"��ӡ��&P��";
				 this->menuItemPrint->Click += gcnew System::EventHandler(this, &MainForm::menuItemPrint_Click);
				 // 
				 // toolStripMenuItem2
				 // 
				 this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
				 this->toolStripMenuItem2->Size = System::Drawing::Size(178, 6);
				 // 
				 // menuItemExit
				 // 
				 this->menuItemExit->Name = L"menuItemExit";
				 this->menuItemExit->Size = System::Drawing::Size(181, 22);
				 this->menuItemExit->Text = L"�˳���&X��";
				 this->menuItemExit->Click += gcnew System::EventHandler(this, &MainForm::menuItemExit_Click);
				 // 
				 // menuItemEdit
				 // 
				 this->menuItemEdit->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->menuItemUndo, 
					 this->menuItemCut, this->menuItemCopy, this->menuItemStick, this->menuItemDel, this->toolStripMenuItem3, this->menuItemFind, 
					 this->menuItemFindNext, this->menuItemReplace, this->menuItemTo, this->toolStripMenuItem4, this->menuItemSelectAll, this->menuItemDayTime});
				 this->menuItemEdit->Name = L"menuItemEdit";
				 this->menuItemEdit->Size = System::Drawing::Size(75, 25);
				 this->menuItemEdit->Text = L"�༭��&E��";
				 this->menuItemEdit->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::menuItemEdit_MouseMove);
				 // 
				 // menuItemUndo
				 // 
				 this->menuItemUndo->Name = L"menuItemUndo";
				 this->menuItemUndo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
				 this->menuItemUndo->Size = System::Drawing::Size(191, 22);
				 this->menuItemUndo->Text = L"������&U��";
				 this->menuItemUndo->Click += gcnew System::EventHandler(this, &MainForm::menuItemUndo_Click);
				 // 
				 // menuItemCut
				 // 
				 this->menuItemCut->Name = L"menuItemCut";
				 this->menuItemCut->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
				 this->menuItemCut->Size = System::Drawing::Size(191, 22);
				 this->menuItemCut->Text = L"���У�&I��";
				 this->menuItemCut->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
				 // 
				 // menuItemCopy
				 // 
				 this->menuItemCopy->Name = L"menuItemCopy";
				 this->menuItemCopy->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
				 this->menuItemCopy->Size = System::Drawing::Size(191, 22);
				 this->menuItemCopy->Text = L"���ƣ�&C��";
				 this->menuItemCopy->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
				 // 
				 // menuItemStick
				 // 
				 this->menuItemStick->Name = L"menuItemStick";
				 this->menuItemStick->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
				 this->menuItemStick->Size = System::Drawing::Size(191, 22);
				 this->menuItemStick->Text = L"ճ��&P��";
				 this->menuItemStick->Click += gcnew System::EventHandler(this, &MainForm::menuItemStick_Click);
				 // 
				 // menuItemDel
				 // 
				 this->menuItemDel->Name = L"menuItemDel";
				 this->menuItemDel->ShortcutKeys = System::Windows::Forms::Keys::Delete;
				 this->menuItemDel->Size = System::Drawing::Size(191, 22);
				 this->menuItemDel->Text = L"ɾ����&L��";
				 this->menuItemDel->Click += gcnew System::EventHandler(this, &MainForm::menuItemDel_Click);
				 // 
				 // toolStripMenuItem3
				 // 
				 this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
				 this->toolStripMenuItem3->Size = System::Drawing::Size(188, 6);
				 // 
				 // menuItemFind
				 // 
				 this->menuItemFind->Name = L"menuItemFind";
				 this->menuItemFind->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
				 this->menuItemFind->Size = System::Drawing::Size(191, 22);
				 this->menuItemFind->Text = L"���ң�&F��...";
				 this->menuItemFind->Click += gcnew System::EventHandler(this, &MainForm::menuItemFind_Click);
				 // 
				 // menuItemFindNext
				 // 
				 this->menuItemFindNext->Name = L"menuItemFindNext";
				 this->menuItemFindNext->ShortcutKeys = System::Windows::Forms::Keys::F3;
				 this->menuItemFindNext->Size = System::Drawing::Size(191, 22);
				 this->menuItemFindNext->Text = L"������һ����&N��";
				 this->menuItemFindNext->Click += gcnew System::EventHandler(this, &MainForm::menuItemFindNext_Click);
				 // 
				 // menuItemReplace
				 // 
				 this->menuItemReplace->Name = L"menuItemReplace";
				 this->menuItemReplace->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
				 this->menuItemReplace->Size = System::Drawing::Size(191, 22);
				 this->menuItemReplace->Text = L"�滻��&R��...";
				 this->menuItemReplace->Click += gcnew System::EventHandler(this, &MainForm::menuItemReplace_Click);
				 // 
				 // menuItemTo
				 // 
				 this->menuItemTo->Name = L"menuItemTo";
				 this->menuItemTo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
				 this->menuItemTo->Size = System::Drawing::Size(191, 22);
				 this->menuItemTo->Text = L"ת����&G��...";
				 this->menuItemTo->Click += gcnew System::EventHandler(this, &MainForm::menuItemTo_Click);
				 // 
				 // toolStripMenuItem4
				 // 
				 this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
				 this->toolStripMenuItem4->Size = System::Drawing::Size(188, 6);
				 // 
				 // menuItemSelectAll
				 // 
				 this->menuItemSelectAll->Name = L"menuItemSelectAll";
				 this->menuItemSelectAll->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F5));
				 this->menuItemSelectAll->Size = System::Drawing::Size(191, 22);
				 this->menuItemSelectAll->Text = L"ȫѡ��&A��";
				 this->menuItemSelectAll->Click += gcnew System::EventHandler(this, &MainForm::menuItemSelectAll_Click);
				 // 
				 // menuItemDayTime
				 // 
				 this->menuItemDayTime->Name = L"menuItemDayTime";
				 this->menuItemDayTime->ShortcutKeys = System::Windows::Forms::Keys::F5;
				 this->menuItemDayTime->Size = System::Drawing::Size(191, 22);
				 this->menuItemDayTime->Text = L"ʱ��/���ڣ�&D��";
				 this->menuItemDayTime->Click += gcnew System::EventHandler(this, &MainForm::menuItemDayTime_Click);
				 // 
				 // menuItemFormat
				 // 
				 this->menuItemFormat->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuItemWrap, 
					 this->menuItemfFont});
				 this->menuItemFormat->Name = L"menuItemFormat";
				 this->menuItemFormat->Size = System::Drawing::Size(78, 25);
				 this->menuItemFormat->Text = L"��ʽ��&O��";
				 // 
				 // menuItemWrap
				 // 
				 this->menuItemWrap->Checked = true;
				 this->menuItemWrap->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->menuItemWrap->Name = L"menuItemWrap";
				 this->menuItemWrap->Size = System::Drawing::Size(160, 22);
				 this->menuItemWrap->Text = L"�Զ����У�&W��";
				 this->menuItemWrap->Click += gcnew System::EventHandler(this, &MainForm::menuItemWrap_Click);
				 // 
				 // menuItemfFont
				 // 
				 this->menuItemfFont->Name = L"menuItemfFont";
				 this->menuItemfFont->Size = System::Drawing::Size(160, 22);
				 this->menuItemfFont->Text = L"����(&F)...";
				 this->menuItemfFont->Click += gcnew System::EventHandler(this, &MainForm::menuItemfFont_Click);
				 // 
				 // menuItemView
				 // 
				 this->menuItemView->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->menuItemState});
				 this->menuItemView->Name = L"menuItemView";
				 this->menuItemView->Size = System::Drawing::Size(76, 25);
				 this->menuItemView->Text = L"�鿴��&V��";
				 // 
				 // menuItemState
				 // 
				 this->menuItemState->Enabled = false;
				 this->menuItemState->Name = L"menuItemState";
				 this->menuItemState->Size = System::Drawing::Size(143, 22);
				 this->menuItemState->Text = L"״̬����&S��";
				 // 
				 // menuItemHelp
				 // 
				 this->menuItemHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuItemAboutTopic, 
					 this->menuItemAbout});
				 this->menuItemHelp->Name = L"menuItemHelp";
				 this->menuItemHelp->Size = System::Drawing::Size(77, 25);
				 this->menuItemHelp->Text = L"������H��";
				 // 
				 // menuItemAboutTopic
				 // 
				 this->menuItemAboutTopic->Name = L"menuItemAboutTopic";
				 this->menuItemAboutTopic->Size = System::Drawing::Size(152, 22);
				 this->menuItemAboutTopic->Text = L"��������(&H)";
				 // 
				 // menuItemAbout
				 // 
				 this->menuItemAbout->Name = L"menuItemAbout";
				 this->menuItemAbout->Size = System::Drawing::Size(152, 22);
				 this->menuItemAbout->Text = L"���ڼ��±�(&A)";
				 this->menuItemAbout->Click += gcnew System::EventHandler(this, &MainForm::menuItemAbout_Click);
				 // 
				 // toolStripComboBox1
				 // 
				 this->toolStripComboBox1->Name = L"toolStripComboBox1";
				 this->toolStripComboBox1->Size = System::Drawing::Size(121, 25);
				 // 
				 // toolStripComboBox2
				 // 
				 this->toolStripComboBox2->Name = L"toolStripComboBox2";
				 this->toolStripComboBox2->Size = System::Drawing::Size(121, 25);
				 // 
				 // toolStrip1
				 // 
				 this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->tlsbtnNew, this->tlsbtnOpen, 
					 this->tlsbtnSave, this->tlsbtnPrint, this->toolStripSeparator1, this->tlsbtnCut, this->tlsbtnCopy, this->tlsbtnPaster, this->toolStripSeparator2, 
					 this->tlsbtnBold, this->tlsbtnItalic, this->tlsbtnUnderline, this->tlsbtnColor});
				 this->toolStrip1->Location = System::Drawing::Point(0, 29);
				 this->toolStrip1->Name = L"toolStrip1";
				 this->toolStrip1->Size = System::Drawing::Size(788, 25);
				 this->toolStrip1->TabIndex = 1;
				 this->toolStrip1->Text = L"toolStrip1";
				 this->toolStrip1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::toolStrip1_MouseMove);
				 // 
				 // tlsbtnNew
				 // 
				 this->tlsbtnNew->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnNew->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnNew.Image")));
				 this->tlsbtnNew->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnNew->Name = L"tlsbtnNew";
				 this->tlsbtnNew->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnNew->ToolTipText = L"�½��հ��ĵ�";
				 this->tlsbtnNew->Click += gcnew System::EventHandler(this, &MainForm::menuItemNew_Click);
				 // 
				 // tlsbtnOpen
				 // 
				 this->tlsbtnOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnOpen.Image")));
				 this->tlsbtnOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnOpen->Name = L"tlsbtnOpen";
				 this->tlsbtnOpen->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnOpen->ToolTipText = L"��";
				 this->tlsbtnOpen->Click += gcnew System::EventHandler(this, &MainForm::menuItemOpen_Click);
				 // 
				 // tlsbtnSave
				 // 
				 this->tlsbtnSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnSave->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnSave.Image")));
				 this->tlsbtnSave->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnSave->Name = L"tlsbtnSave";
				 this->tlsbtnSave->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnSave->ToolTipText = L"����";
				 this->tlsbtnSave->Click += gcnew System::EventHandler(this, &MainForm::menuItemSave_Click);
				 // 
				 // tlsbtnPrint
				 // 
				 this->tlsbtnPrint->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnPrint->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnPrint.Image")));
				 this->tlsbtnPrint->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnPrint->Name = L"tlsbtnPrint";
				 this->tlsbtnPrint->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnPrint->Text = L"��ӡ";
				 this->tlsbtnPrint->Click += gcnew System::EventHandler(this, &MainForm::menuItemPrint_Click);
				 // 
				 // toolStripSeparator1
				 // 
				 this->toolStripSeparator1->Name = L"toolStripSeparator1";
				 this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
				 // 
				 // tlsbtnCut
				 // 
				 this->tlsbtnCut->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnCut->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnCut.Image")));
				 this->tlsbtnCut->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnCut->Name = L"tlsbtnCut";
				 this->tlsbtnCut->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnCut->ToolTipText = L"����";
				 this->tlsbtnCut->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
				 // 
				 // tlsbtnCopy
				 // 
				 this->tlsbtnCopy->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnCopy->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnCopy.Image")));
				 this->tlsbtnCopy->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnCopy->Name = L"tlsbtnCopy";
				 this->tlsbtnCopy->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnCopy->ToolTipText = L"����";
				 this->tlsbtnCopy->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
				 // 
				 // tlsbtnPaster
				 // 
				 this->tlsbtnPaster->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnPaster->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnPaster.Image")));
				 this->tlsbtnPaster->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnPaster->Name = L"tlsbtnPaster";
				 this->tlsbtnPaster->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnPaster->ToolTipText = L"ճ��";
				 this->tlsbtnPaster->Click += gcnew System::EventHandler(this, &MainForm::menuItemStick_Click);
				 // 
				 // toolStripSeparator2
				 // 
				 this->toolStripSeparator2->Name = L"toolStripSeparator2";
				 this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
				 // 
				 // tlsbtnBold
				 // 
				 this->tlsbtnBold->CheckOnClick = true;
				 this->tlsbtnBold->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnBold->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnBold.Image")));
				 this->tlsbtnBold->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnBold->Name = L"tlsbtnBold";
				 this->tlsbtnBold->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnBold->ToolTipText = L"����";
				 this->tlsbtnBold->CheckedChanged += gcnew System::EventHandler(this, &MainForm::tlsbtnBold_CheckedChanged);
				 this->tlsbtnBold->Click += gcnew System::EventHandler(this, &MainForm::tlsbtnBold_Click);
				 // 
				 // tlsbtnItalic
				 // 
				 this->tlsbtnItalic->CheckOnClick = true;
				 this->tlsbtnItalic->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnItalic->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnItalic.Image")));
				 this->tlsbtnItalic->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnItalic->Name = L"tlsbtnItalic";
				 this->tlsbtnItalic->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnItalic->ToolTipText = L"б��";
				 this->tlsbtnItalic->CheckedChanged += gcnew System::EventHandler(this, &MainForm::tlsbtnItalic_CheckedChanged);
				 // 
				 // tlsbtnUnderline
				 // 
				 this->tlsbtnUnderline->CheckOnClick = true;
				 this->tlsbtnUnderline->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnUnderline->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnUnderline.Image")));
				 this->tlsbtnUnderline->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnUnderline->Name = L"tlsbtnUnderline";
				 this->tlsbtnUnderline->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnUnderline->ToolTipText = L"�»���";
				 this->tlsbtnUnderline->CheckedChanged += gcnew System::EventHandler(this, &MainForm::tlsbtnUnderline_CheckedChanged);
				 // 
				 // tlsbtnColor
				 // 
				 this->tlsbtnColor->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->tlsbtnColor->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnColor.Image")));
				 this->tlsbtnColor->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->tlsbtnColor->Name = L"tlsbtnColor";
				 this->tlsbtnColor->Size = System::Drawing::Size(23, 22);
				 this->tlsbtnColor->ToolTipText = L"������ɫ";
				 this->tlsbtnColor->Click += gcnew System::EventHandler(this, &MainForm::tlsbtnColor_Click);
				 // 
				 // txtBoxMain
				 // 
				 this->txtBoxMain->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->txtBoxMain->Location = System::Drawing::Point(0, 54);
				 this->txtBoxMain->Multiline = true;
				 this->txtBoxMain->Name = L"txtBoxMain";
				 this->txtBoxMain->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				 this->txtBoxMain->Size = System::Drawing::Size(788, 259);
				 this->txtBoxMain->TabIndex = 2;
				 this->txtBoxMain->TextChanged += gcnew System::EventHandler(this, &MainForm::textChanged);
				 this->txtBoxMain->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::keyDownOnTextBox);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // printDocument1
				 // 
				 this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainForm::printDocument1_PrintPage);
				 // 
				 // contextMenuStrip1
				 // 
				 this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->����ToolStripMenuItem, 
					 this->toolStripSeparator3, this->����ToolStripMenuItem, this->����CToolStripMenuItem, this->ճ��VToolStripMenuItem, this->ɾ��DelToolStripMenuItem, 
					 this->toolStripMenuItem5, this->ȫѡAToolStripMenuItem, this->toolStripMenuItem6});
				 this->contextMenuStrip1->Name = L"contextMenuStrip1";
				 this->contextMenuStrip1->Size = System::Drawing::Size(144, 154);
				 // 
				 // ����ToolStripMenuItem
				 // 
				 this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
				 this->����ToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->����ToolStripMenuItem->Text = L"������&U��";
				 this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemUndo_Click);
				 // 
				 // toolStripSeparator3
				 // 
				 this->toolStripSeparator3->Name = L"toolStripSeparator3";
				 this->toolStripSeparator3->Size = System::Drawing::Size(140, 6);
				 // 
				 // ����ToolStripMenuItem
				 // 
				 this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
				 this->����ToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->����ToolStripMenuItem->Text = L"���У�&I��";
				 this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
				 // 
				 // ����CToolStripMenuItem
				 // 
				 this->����CToolStripMenuItem->Name = L"����CToolStripMenuItem";
				 this->����CToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->����CToolStripMenuItem->Text = L"���ƣ�&C��";
				 this->����CToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
				 // 
				 // ճ��VToolStripMenuItem
				 // 
				 this->ճ��VToolStripMenuItem->Name = L"ճ��VToolStripMenuItem";
				 this->ճ��VToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->ճ��VToolStripMenuItem->Text = L"ճ����&V��";
				 this->ճ��VToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemStick_Click);
				 // 
				 // ɾ��DelToolStripMenuItem
				 // 
				 this->ɾ��DelToolStripMenuItem->Name = L"ɾ��DelToolStripMenuItem";
				 this->ɾ��DelToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->ɾ��DelToolStripMenuItem->Text = L"ɾ����Del��";
				 this->ɾ��DelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemDel_Click);
				 // 
				 // toolStripMenuItem5
				 // 
				 this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
				 this->toolStripMenuItem5->Size = System::Drawing::Size(140, 6);
				 // 
				 // ȫѡAToolStripMenuItem
				 // 
				 this->ȫѡAToolStripMenuItem->Name = L"ȫѡAToolStripMenuItem";
				 this->ȫѡAToolStripMenuItem->Size = System::Drawing::Size(143, 22);
				 this->ȫѡAToolStripMenuItem->Text = L"ȫѡ��&A��";
				 this->ȫѡAToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemSelectAll_Click);
				 // 
				 // toolStripMenuItem6
				 // 
				 this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
				 this->toolStripMenuItem6->Size = System::Drawing::Size(140, 6);
				 // 
				 // fontDialog1
				 // 
				 this->fontDialog1->Color = System::Drawing::SystemColors::ControlText;
				 // 
				 // TipBox
				 // 
				 this->TipBox->BackColor = System::Drawing::SystemColors::Menu;
				 this->TipBox->Enabled = false;
				 this->TipBox->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(134)));
				 this->TipBox->FormattingEnabled = true;
				 this->TipBox->HorizontalScrollbar = true;
				 this->TipBox->ItemHeight = 17;
				 this->TipBox->Location = System::Drawing::Point(58, 77);
				 this->TipBox->MaximumSize = System::Drawing::Size(300, 300);
				 this->TipBox->Name = L"TipBox";
				 this->TipBox->Size = System::Drawing::Size(222, 174);
				 this->TipBox->TabIndex = 3;
				 this->TipBox->Visible = false;
				 this->TipBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::selectIndexChangedOnTipBox);
				 this->TipBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::keyDownOnTipBox);
				 this->TipBox->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::mouseDoubleClickOnTipBox);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(788, 313);
				 this->Controls->Add(this->TipBox);
				 this->Controls->Add(this->txtBoxMain);
				 this->Controls->Add(this->toolStrip1);
				 this->Controls->Add(this->menuStrip1);
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MainForm";
				 this->Text = L"�ޱ��⡪���±�";
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
				 this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->toolStrip1->ResumeLayout(false);
				 this->toolStrip1->PerformLayout();
				 this->contextMenuStrip1->ResumeLayout(false);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void menuItemNew_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain->Text ="";
			 }
	private: System::Void menuItemOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->openFileDialog1 ->Filter="�ı��ļ�(.txt)|*.txt|�����ļ�(*.*)|*.*";
				 try
				 {
					 if(this->openFileDialog1 ->ShowDialog ()==System::Windows ::Forms ::DialogResult ::OK )
					 {
						 String^ name = this->openFileDialog1 ->FileName ;
						 this->Text = name +"-���±�";
						 this->openFileDialog1 ->Title ="��";
						 System::IO ::StreamReader^ reader = gcnew System::IO::StreamReader (name,System::Text::Encoding ::Default );
						 String^ readAll = reader->ReadToEnd ();
						 this->txtBoxMain ->Text = readAll;
						 reader->Close ();
					 }
				 }
				 catch (IOException^ e)
				 {
					 Console::WriteLine ("an IOException has been thrown!");
					 Console::WriteLine (e->ToString ());
					 return ;
				 }

			 }


	private: System::Void menuItemSave_Click(System::Object^  sender, System::EventArgs^  e) {
				 save();
			 }
	private: System::Void menuItemSaveAs_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->saveFileDialog1 ->ShowDialog ()==System::Windows ::Forms ::DialogResult ::OK )
				 {
					 String^ name = this->saveFileDialog1 ->FileName ;
					 this->saveFileDialog1 ->Filter ="�ı��ļ�(.txt)|*.txt|�����ļ�(*.*)|*.*";
					 try 
					 {
						 File::WriteAllText (name,this->txtBoxMain ->Text );
					 }
					 catch(System::IO ::IOException^ ex)
					 {
						 MessageBox::Show ( ex->Message  , "���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
					 }}
			 }
	private: System::Void menuItemPageSetup_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->pageSetupDialog1 ->Document =this->printDocument1 ;
				 this->pageSetupDialog1 ->ShowDialog ();
			 }
	private: System::Void menuItemPrint_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {
					 this->printDocument1 ->Print ();
				 }
				 catch(Exception^ ex)
				 {
					 MessageBox::Show(ex->Message ,"���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
				 }
			 }
	private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
				 array<Char>^ param ={'\n'};
				 array<String^>^ lines = this->txtBoxMain ->Text ->Split (param);

				 char trimParam= '\r';
				 for(int i =0;i<lines->Length ;i++)
				 {
					 lines[i]= lines[i]->TrimEnd (trimParam);
				 }
				 float x=20;
				 float y=20;

				 for(int i =0;i<lines->Length ;i++)
				 {
					 e->Graphics->DrawString (lines[i],gcnew System::Drawing ::Font("Arial",10),Brushes::Black ,x,y);
					 y+=15;
				 }
			 }
	private: System::Void menuItemExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close ();
			 }
	private: System::Void menuItemCut_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->Cut ();
			 }
	private: System::Void menuItemCopy_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->Copy ();
			 }
	private: System::Void menuItemStick_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->Paste ();
			 }
	private: System::Void menuItemDel_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->SelectedText ="";
			 }
	private: System::Void menuItemSelectAll_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->SelectAll ();
			 }
	private: System::Void menuItemUndo_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->Undo ();
			 }
	private: System::Void menuItemfFont_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->fontDialog1->ShowDialog() ==Windows::Forms ::DialogResult ::OK )
				 {
					 this->txtBoxMain ->Font =this->fontDialog1 ->Font ;
				 }
			 }
	private: System::Void menuItemDayTime_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txtBoxMain ->Text = System::DateTime ::Now.ToString ();
			 }
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 System::Windows ::Forms ::DialogResult result=Windows::Forms ::MessageBox ::Show ("�ļ�"+this->Text +"���޸ģ��Ƿ�Ҫ����","���±�",MessageBoxButtons::YesNoCancel ,MessageBoxIcon::Exclamation )	;
				 if(result==System::Windows ::Forms ::DialogResult::Yes )
				 {
					 save();
				 }
				 if(result==System::Windows ::Forms ::DialogResult::No )
				 {
					 //this->Close ();
				 }
				 if(result==System::Windows ::Forms ::DialogResult::Cancel )
				 {
					 e->Cancel = true;
				 }
			 }
	private: System::Void menuItemEdit_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(this->txtBoxMain ->SelectedText =="")
				 {
					 if(this->txtBoxMain ->Text =="")
					 {

						 this->menuItemUndo ->Enabled =false;
						 this->menuItemFind ->Enabled =false;
						 this->menuItemFindNext ->Enabled =false;
						 this->menuItemReplace ->Enabled =false;
					 }
					 else
					 {
						 this->menuItemUndo ->Enabled =true;
						 this->menuItemFind ->Enabled =true;
						 this->menuItemFindNext ->Enabled =true;
						 this->menuItemReplace ->Enabled =true;
					 }
					 this->menuItemCopy ->Enabled =false;
					 this->menuItemCut ->Enabled =false;
					 this->menuItemDel ->Enabled =false;
				 }
				 else 
				 {

					 this->menuItemCopy ->Enabled =true;
					 this->menuItemCut ->Enabled =true;
					 this->menuItemDel ->Enabled =true;	

				 }
				 if(this->menuItemWrap ->Checked ==true)
				 {
					 this->menuItemTo ->Enabled =false;
				 }
				 else 
				 {
					 this->menuItemTo ->Enabled =true;
				 }
			 }



	private: System::Void tlsbtnBold_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Drawing ::Font^ oldFont;
				 System::Drawing ::Font^ newFont;
				 bool checkState =((Windows::Forms ::ToolStripButton^)sender)->Checked ;

				 oldFont = this->txtBoxMain ->Font;

				 if(!checkState)
				 {
					 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style & ~FontStyle::Bold);
				 }
				 else
				 {
					 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style | FontStyle::Bold);

				 }
				 this->txtBoxMain ->Font = newFont;
				 this->txtBoxMain ->Focus ();

			 }

	private: System::Void tlsbtnItalic_CheckedChanged(System::Object^  sender, System::EventArgs^  e) { System::Drawing ::Font^ oldFont;
			 System::Drawing ::Font^ newFont;
			 bool checkState =((Windows::Forms ::ToolStripButton^)sender)->Checked ;

			 oldFont = this->txtBoxMain ->Font;

			 if(!checkState)
			 {
				 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style & ~FontStyle::Italic );
			 }
			 else
			 {
				 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style | FontStyle::Italic );

			 }
			 this->txtBoxMain ->Font = newFont;
			 this->txtBoxMain ->Focus ();


			 }
	private: System::Void tlsbtnUnderline_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Drawing ::Font^ oldFont;
				 System::Drawing ::Font^ newFont;
				 bool checkState =((Windows::Forms ::ToolStripButton^)sender)->Checked ;

				 oldFont = this->txtBoxMain ->Font;

				 if(!checkState)
				 {
					 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style & ~FontStyle::Underline );
				 }
				 else
				 {
					 newFont = gcnew System::Drawing ::Font(oldFont,oldFont->Style | FontStyle::Underline );

				 }
				 this->txtBoxMain ->Font = newFont;
				 this->txtBoxMain ->Focus ();


			 }
	private: System::Void menuItemFind_Click(System::Object^  sender, System::EventArgs^  e) {


				 SearchForm^ search =gcnew SearchForm();

				 search->ShowDialog();

				 if(this->txtBoxMain ->Text ->Length >0)
				 { 
					 int index;
					 if(  search->lower )
					 { 
						 index = search->find (this->txtBoxMain ->Text);
					 }
					 else
					 {
						 index = search->find (this->txtBoxMain ->Text ->ToLower ());
					 }

					 if(index == -1)
					 {
						 System::Windows ::Forms ::MessageBox ::Show ("û��������"+search->str ,"���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
						 search->FindPlace = 0;
					 }
					 else
					 {
						 this->txtBoxMain ->Select (search->FindPlace ,search->str ->Length );
						 search->FindPlace =search->FindPlace + search->str ->Length ;
					 }

				 }
				 this->Activate ();

			 }
	private: System::Void tlsbtnColor_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->colorDialog1 ->ShowDialog ()==System::Windows ::Forms ::DialogResult ::OK )
					 this->txtBoxMain->ForeColor = this->colorDialog1->Color ;
			 }
	private: System::Void menuItemReplace_Click(System::Object^  sender, System::EventArgs^  e) {
				 ReplaceForm^ replace = gcnew ReplaceForm(); 
				 replace->ShowDialog ();
				 if(this->txtBoxMain ->Text ->Length >0)
				 {
					 int index;
					 if(replace->lower )
					 {
						 index = replace->Replace(this->txtBoxMain ->Text );
					 }
					 else
					 {
						 index = replace->Replace  (this->txtBoxMain ->Text ->ToLower ());
					 }
					 if(index == -1)
					 {
						 System::Windows ::Forms ::MessageBox ::Show ("û��������"+replace->strSearch    ,"���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
						 replace->FindPlace =0;
					 }
					 else
					 { 
						 if(replace->replaceAll == true )

						 {
							 this->txtBoxMain->Text=this->txtBoxMain->Text->Replace(replace->strSearch ,replace->strReplace  );
						 }
						 else
						 {
							 this->txtBoxMain->Select (replace->FindPlace ,replace->strSearch  ->Length );

							 replace->FindPlace = replace->FindPlace + replace->strSearch ->Length ;

							 this->txtBoxMain ->SelectedText = replace->strReplace ;

						 }



					 }
					 this->Activate ();

				 }
			 }

	private: System::Void menuItemAbout_Click(System::Object^  sender, System::EventArgs^  e) {
				 AboutForm^ about = gcnew AboutForm();
				 about->ShowDialog  ();

			 }
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 if(this->txtBoxMain ->SelectedText != "")
				 {
					 this->tlsbtnCut ->Enabled =true;
					 this->tlsbtnCopy ->Enabled =true;
				 }
				 else
				 {
					 this->tlsbtnCut ->Enabled =false;
					 this->tlsbtnCopy ->Enabled =false;
				 }
			 }
	private: System::Void menuItemFindNext_Click(System::Object^  sender, System::EventArgs^  e) {


				 SearchForm^ search =gcnew SearchForm();
				 search->ShowDialog ();

				 if(this->txtBoxMain ->Text ->Length >0)
				 {
					 int index = search->find (this->txtBoxMain ->Text );
					 if(index == -1)
					 {
						 System::Windows ::Forms ::MessageBox ::Show ("û��������"+search->str ,"���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
						 search->FindPlace = 0;
					 }
					 else
					 {
						 this->txtBoxMain->Select (search->FindPlace ,search->str ->Length  );
						 search->FindPlace =search->FindPlace + search->str ->Length ;
					 }

				 }
				 this->Activate ();

			 }
	public: void save()
			{
				String^ name = this ->openFileDialog1 ->FileName ;
				try{
					if(File::Exists (name))
					{

						File::WriteAllText (name,this->txtBoxMain ->Text);
					}
					else
					{
						this->saveFileDialog1->Filter = "(Text.txt)|*.txt|(All File)|*.*";
						if(this->saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
						{
							String^ name = this->saveFileDialog1->FileName;
							StreamWriter^ writer = gcnew StreamWriter(name,false,System::Text::Encoding::Default);
							writer->Write(this->txtBoxMain->Text);
							this->Text = name +"-���±�";
							writer->Close();
						}
					}
				}
				catch(System::IO ::IOException^ ex)
				{
					MessageBox::Show ( ex->Message  , "���±�",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
				}
			}


	private: System::Void toolStrip1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(this->txtBoxMain ->SelectedText != "")
				 {
					 this->tlsbtnCut ->Enabled =true;
					 this->tlsbtnCopy ->Enabled =true;
				 }
				 else
				 {
					 this->tlsbtnCut ->Enabled =false;
					 this->tlsbtnCopy ->Enabled =false;
				 }
			 }
	private: System::Void menuItemTo_Click(System::Object^  sender, System::EventArgs^  e) {
				 ToForm^ to =gcnew ToForm();
				 to->ShowDialog ();
				 to->point ();
				 if(to->selectItem ="��ͷ")
				 {
					 this->txtBoxMain ->SelectionStart =0;
				 }
				 else
				 { 
					 int index =this->txtBoxMain ->Text ->Length-1;
					 this->txtBoxMain ->SelectionStart =index;


				 }
			 }
	private: System::Void menuItemWrap_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->menuItemWrap ->Checked =!(this->menuItemWrap ->Checked);
				 this->txtBoxMain ->WordWrap =!(this->txtBoxMain ->WordWrap) ;

			 }
	private: System::Void tlsbtnBold_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (m_bNeedProcessTextChanged)
				 {
					 String^ text = this->txtBoxMain->Text;
					 //ȡ�õ�ǰ��������е�ƥ��λ�ã�����ǰ�еĿ�ͷ
					 m_nIndex = 0;
					 array<String^>^ lines = this->txtBoxMain->Text->Substring(0,this->txtBoxMain->SelectionStart)->Split('\n');
					 for (int i=0;i<lines->Length - 1;i++)
					 {
						 m_nIndex += lines[i]->Length;
						 //���ϻ���
						 m_nIndex += 1;
					 }
					 SetTipBox();
				 }

			 }
	private: System::Void mouseDoubleClickOnTipBox(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 AddSelectString();
			 }

	private: System::Void keyDownOnTextBox(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
// 				 char temp[255];
// 				 sprintf(temp,"control:%d  left:%d leftControl is %d left is %d",(int)ModifierKeys,(int)e->KeyCode,(int)Keys::Control,(int)Keys::Left);
// 				 Debug::WriteLine(gcnew String(temp));

				 //��ϼ�
				 if (ModifierKeys == Keys::Control && e->KeyCode == Keys::Left)
				 { 
					 int curPos = this->txtBoxMain->SelectionStart;
					 String^ text = this->txtBoxMain->Text;
					 int lineStart = -1;
					 if(curPos >= this->txtBoxMain->Text->Length)
						lineStart = text->LastIndexOf('\n',curPos-1);
					 else
						 lineStart = text->LastIndexOf('\n',curPos);
					 String^ line;
					 if(lineStart == -1)
						 line = text->Substring(0,curPos);
					 else
						 line = text->Substring(lineStart+1,curPos-lineStart-1);

					 if(SelectVarialbeName(line,(lineStart==-1)?0:lineStart,false))
						 e->SuppressKeyPress = true;
					 return;
				 }
				 else if (e->Modifiers == Keys::Control && e->KeyCode == Keys::Right)
				 {
					 //���Ҳ�����һ�����������Ȱѹ���Ƶ���ǰѡ�б������ұ�
					 this->txtBoxMain->SelectionStart = this->txtBoxMain->SelectionStart + this->txtBoxMain->SelectionLength;

					 int curPos = this->txtBoxMain->SelectionStart;
					 String^ text = this->txtBoxMain->Text;
					 int lineStart = text->IndexOf('\n',curPos);
					 String^ line;
					 if(lineStart == -1)
						 line = text->Substring(curPos,text->Length-curPos);
					 else
						 line = text->Substring(curPos,lineStart-curPos-1);

					 if(SelectVarialbeName(line,curPos,true))
						 e->SuppressKeyPress = true;

					 return;
				 }

				 if (e->KeyCode == Keys::Escape)
				 {
					 if (TipBox->Enabled == true && TipBox->Visible == true)
					 {
						 TipBox->Enabled = false;
						 TipBox->Visible = false;
					 }
				 }
				 else if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab)
				 {
					 //���»س���table���Ҵ���ѡ���б�ʱ��д��ѡ����
					 if (TipBox->Enabled == true && TipBox->Visible == true && TipBox->SelectedIndex != -1)
					 {
						 AddSelectString();
						 //��Ҫ����������
						 e->SuppressKeyPress = true;
					 }
				 }
				 else if (e->KeyCode ==  Keys::Up)
				 {
					 if(TipBox->SelectedIndex > 0)
					 {
						 TipBox->SelectedIndex--;
					 }
					 if (TipBox->Visible == true && TipBox->Enabled == true)
					 {
						 //���ع���ƶ�
						 e->SuppressKeyPress = true;
					 }

				 }
				 else if (e->KeyCode == Keys::Down)
				 {
					 if(TipBox->SelectedIndex < TipBox->Items->Count - 1)
					 {
						 TipBox->SelectedIndex++;
					 }			
					 if (TipBox->Visible == true && TipBox->Enabled == true)
					 {
						 //���ع���ƶ�
						 e->SuppressKeyPress = true;
					 }
				 }
				 else if (e->KeyCode == Keys::Left)
				 {
					 if(TipBox->SelectedIndex < TipBox->Items->Count - 1)
					 {
						 SendMessage(TipBox->Handle, WM_HSCROLL, (IntPtr)SB_PAGELEFT , IntPtr::Zero);
					 }
					 if (TipBox->Visible == true && TipBox->Enabled == true)
					 {
						 //���ع���ƶ�
						 e->SuppressKeyPress = true;
					 }
				 }
				 else if (e->KeyCode == Keys::Right)
				 {
					 if(TipBox->SelectedIndex < TipBox->Items->Count - 1)
					 {
						SendMessage(TipBox->Handle, WM_HSCROLL, (IntPtr)SB_PAGERIGHT , IntPtr::Zero);
					 }
					 if (TipBox->Visible == true && TipBox->Enabled == true)
					 {
						 //���ع���ƶ�
						 e->SuppressKeyPress = true;
					 }
				 }
			 }
	private: System::Void keyDownOnTipBox(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::Enter)
				 {
					 AddSelectString();
				 }

			 }

			 bool SetTipBox()
			 {
				 String^ text = this->txtBoxMain->Text;
				 bool result = true;
				 TipBox->Items->Clear();
				 if(this->txtBoxMain->SelectionStart < m_nIndex)
				 {
					 result = false;		
				 }
				 else
				 {
					 String^ testString = text->Substring(m_nIndex,this->txtBoxMain->SelectionStart-m_nIndex);
					 if (String::IsNullOrEmpty(testString))
					 {
						 result = false;
					 }
					 else
					 {
						 TipBox->BeginUpdate();
						 for (map<String^,String^>::iterator it=m_MDatabase.begin();it!=m_MDatabase.end();it++)
						 {
							 String^ matchString = it->first;
							 matchString = matchString->ToUpper();
							 if(matchString->StartsWith(testString->ToUpper()))
							 {			 
								 TipBox->Items->Add(it->first);
							 }
						 }
						 TipBox->EndUpdate();
					 }


					 if(TipBox->Items->Count > 0)
					 {
						 //�ƶ�λ��
						 Point pos = this->txtBoxMain->GetPositionFromCharIndex(this->txtBoxMain->SelectionStart-1);
						 pos.X += 20;
						 pos.Y += 60;
						 TipBox->Location = pos;
						 result = true;
					 }
					 else
					 {
						 result = false;
					 }
				 }

				 TipBox->Enabled = result;
				 TipBox->Visible = result;
				 //Ҫ����ʾTipBox֮����ѡ��Ĭ���������ʾ tip�������
				 if(TipBox->Items->Count > 0)
					 TipBox->SetSelected(0,true);
				 ShowOrHideToolTip();

				 return result;
			 }

			 void AddSelectString()
			 {
				 if (m_nIndex < this->txtBoxMain->Text->Length)
				 {		 
					 //������Ҫ��Ǵ�ʱ������Ϊ����textbox�ı�����ֹTextChanged����
					 m_bNeedProcessTextChanged = false;

					 //���Ƴ�ƥ��Ĳ��֣�Ȼ�����ѡ�е���
					 //�������ݻ��������滻
					 String^ head = this->txtBoxMain->Text->Substring(0,m_nIndex);
					 int enterPos = this->txtBoxMain->Text->IndexOf('\n',m_nIndex);
					 if(enterPos == -1)
						 enterPos = this->txtBoxMain->Text->Length;
					 else
						 enterPos -- ;
					 String^ tail = this->txtBoxMain->Text->Substring(enterPos);
					 this->txtBoxMain->Text = head;
					 this->txtBoxMain->AppendText(TipBox->SelectedItem->ToString());
					 //��¼����ʱ�Ľ�β��Ϊ�˽�����ƶ���ȥ
					 int lastPos = this->txtBoxMain->Text->Length;

					 this->txtBoxMain->AppendText(tail);
					 //�ƶ����
					 this->txtBoxMain->SelectionStart = lastPos;

					 //������TextChanged��Ч
					 m_bNeedProcessTextChanged = true;

					 //ѡ�е�һ��������
					 SelectVarialbeName(TipBox->SelectedItem->ToString(),m_nIndex,true);

					 TipBox->Enabled = false;
					 TipBox->Hide();
					 ShowOrHideToolTip();
				 }			 
			 }

			 bool SelectVarialbeName(String^ value,int index,bool forward)
			 {
				 //ָ��Ҫ�޸ĵ��ı�����
				 Int32 flag;
				 if(forward)
					 flag = value->IndexOf("$",0);
				 else
					 flag = value->LastIndexOf("$",value->Length);
				 if (flag != -1)
				 {
					 Int32 tail;
					 if(forward)
						 tail = value->IndexOf("$",flag+1);
					 else
						 tail = value->LastIndexOf("$",flag-1);
					 if (tail != -1)
					 {
						 //Ҫ��֤flag��tail֮��û�пո��Լ����С������
						 String^ variable;
						 if(forward)
							 variable = value->Substring(flag+1,tail-flag-1);
						 else
							 variable = value->Substring(tail+1,flag-tail-1);
						 if (!variable->Contains(" ") && !variable->Contains("\n") && !variable->Contains("\r"))
						 {
							 //ȷ���ҵ��˸ñ��������������������ͷ������ѡ����������������$����
							 if(forward)
							 {
								 this->txtBoxMain->SelectionStart = flag + index;
								 this->txtBoxMain->SelectionLength = tail - flag + 1;
							 }
							 else
							 {
								 this->txtBoxMain->SelectionStart = tail + index + 1;
								 this->txtBoxMain->SelectionLength = flag - tail + 1;
							 }
							 return true;
						 }
					 }
				 }
				 return false;
			 }

	private: System::Void selectIndexChangedOnTipBox(System::Object^  sender, System::EventArgs^  e) {
				 ShowOrHideToolTip();
			 }

			 void ShowOrHideToolTip()
			 {
				 if (TipBox->Enabled == true && TipBox->Visible == true && TipBox->SelectedIndex != -1)
				 {
					 //��ȡTipBox����λ��
					 Rectangle^ rect = TipBox->Bounds;
					 //��ȡ����
					 String^ explanation;
					 map<String^,String^>::iterator it = m_MDatabase.find(TipBox->SelectedItem->ToString());
					 if(it != m_MDatabase.end())
						 explanation = it->second;
					 String^ newToolTip;
					 //���Ƴ���
					 int i=0;
					 for (;i<explanation->Length/m_snCharsPerLine;i++)
					 {
						 newToolTip += explanation->Substring(i*m_snCharsPerLine,m_snCharsPerLine);
						 //������ֱ��ضϣ�����ָ���ǵ��ʣ������һ�����ַ�-
						 int markPos = i*m_snCharsPerLine + m_snCharsPerLine;
						 if (markPos + 1 < explanation->Length)
						 {
							 if((explanation[markPos] != ' ' || explanation[markPos] != '\n' || explanation[markPos] != '\r') &&
								 (explanation[markPos+1] != ' ' || explanation[markPos+1] != '\n' || explanation[markPos+1] != '\r'))
							 {
								 newToolTip += "-";
							 }
						 }
						 
						 newToolTip += Environment::NewLine;
					 }
					 newToolTip += explanation->Substring(i*m_snCharsPerLine,explanation->Length-i*m_snCharsPerLine);
					 this->toolTip->Show(newToolTip,TipBox,rect->Width,0);
					 //this->toolTip->Active = true;
				 }
				 else
				 {
					 this->toolTip->Hide(this);
				 }
			 }
};
}