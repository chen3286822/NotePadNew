#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO ;
using namespace System::Drawing ::Printing ;
#include "SearchForm1.h"
#include "ReplaceForm.h"
#include  "AboutForm.h"
#include "ToForm1.h"
#include <cliext/vector>
using namespace cliext;
 


namespace WordPad {

	/// <summary>
	/// MainForm 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			System::IO ::StreamReader^ reader = gcnew System::IO::StreamReader ("step.txt",System::Text::Encoding ::Default );
			while (!reader->EndOfStream)
			{
				String^ sentense = reader->ReadLine();
				m_VDatabase.push_back(sentense);
			}
			m_nIndex = -1;
			m_bNeedProcessTextChanged = true;
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
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
	private: System::Windows::Forms::ToolStripMenuItem^  撤销ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  剪切ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  复制CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  粘贴VToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  删除DelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  全选AToolStripMenuItem;
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
		/// 必需的设计器变量。
		/// </summary>
		vector<String^> m_VDatabase;
		int m_nIndex;		//记录开始识别的位置
		bool m_bNeedProcessTextChanged;	//标记是否需要textChanged事件处理

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
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
			this->撤销ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->剪切ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->复制CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->粘贴VToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->删除DelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->全选AToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->TipBox = (gcnew System::Windows::Forms::ListBox());
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
			this->menuItemFile->Text = L"文件（&F）";
			// 
			// menuItemNew
			// 
			this->menuItemNew->Name = L"menuItemNew";
			this->menuItemNew->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->menuItemNew->Size = System::Drawing::Size(181, 22);
			this->menuItemNew->Text = L"新建（&N）";
			this->menuItemNew->Click += gcnew System::EventHandler(this, &MainForm::menuItemNew_Click);
			// 
			// menuItemOpen
			// 
			this->menuItemOpen->Name = L"menuItemOpen";
			this->menuItemOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->menuItemOpen->Size = System::Drawing::Size(181, 22);
			this->menuItemOpen->Text = L"打开（&O）";
			this->menuItemOpen->Click += gcnew System::EventHandler(this, &MainForm::menuItemOpen_Click);
			// 
			// menuItemSave
			// 
			this->menuItemSave->Name = L"menuItemSave";
			this->menuItemSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->menuItemSave->Size = System::Drawing::Size(181, 22);
			this->menuItemSave->Text = L"保存（&S）";
			this->menuItemSave->Click += gcnew System::EventHandler(this, &MainForm::menuItemSave_Click);
			// 
			// menuItemSaveAs
			// 
			this->menuItemSaveAs->Name = L"menuItemSaveAs";
			this->menuItemSaveAs->Size = System::Drawing::Size(181, 22);
			this->menuItemSaveAs->Text = L"另存为（&A）...";
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
			this->menuItemPageSetup->Text = L"页面设置（&U）...";
			this->menuItemPageSetup->Click += gcnew System::EventHandler(this, &MainForm::menuItemPageSetup_Click);
			// 
			// menuItemPrint
			// 
			this->menuItemPrint->Name = L"menuItemPrint";
			this->menuItemPrint->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->menuItemPrint->Size = System::Drawing::Size(181, 22);
			this->menuItemPrint->Text = L"打印（&P）";
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
			this->menuItemExit->Text = L"退出（&X）";
			this->menuItemExit->Click += gcnew System::EventHandler(this, &MainForm::menuItemExit_Click);
			// 
			// menuItemEdit
			// 
			this->menuItemEdit->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->menuItemUndo, 
				this->menuItemCut, this->menuItemCopy, this->menuItemStick, this->menuItemDel, this->toolStripMenuItem3, this->menuItemFind, 
				this->menuItemFindNext, this->menuItemReplace, this->menuItemTo, this->toolStripMenuItem4, this->menuItemSelectAll, this->menuItemDayTime});
			this->menuItemEdit->Name = L"menuItemEdit";
			this->menuItemEdit->Size = System::Drawing::Size(75, 25);
			this->menuItemEdit->Text = L"编辑（&E）";
			this->menuItemEdit->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::menuItemEdit_MouseMove);
			// 
			// menuItemUndo
			// 
			this->menuItemUndo->Name = L"menuItemUndo";
			this->menuItemUndo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->menuItemUndo->Size = System::Drawing::Size(191, 22);
			this->menuItemUndo->Text = L"撤销（&U）";
			this->menuItemUndo->Click += gcnew System::EventHandler(this, &MainForm::menuItemUndo_Click);
			// 
			// menuItemCut
			// 
			this->menuItemCut->Name = L"menuItemCut";
			this->menuItemCut->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->menuItemCut->Size = System::Drawing::Size(191, 22);
			this->menuItemCut->Text = L"剪切（&I）";
			this->menuItemCut->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
			// 
			// menuItemCopy
			// 
			this->menuItemCopy->Name = L"menuItemCopy";
			this->menuItemCopy->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->menuItemCopy->Size = System::Drawing::Size(191, 22);
			this->menuItemCopy->Text = L"复制（&C）";
			this->menuItemCopy->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
			// 
			// menuItemStick
			// 
			this->menuItemStick->Name = L"menuItemStick";
			this->menuItemStick->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->menuItemStick->Size = System::Drawing::Size(191, 22);
			this->menuItemStick->Text = L"粘贴&P）";
			this->menuItemStick->Click += gcnew System::EventHandler(this, &MainForm::menuItemStick_Click);
			// 
			// menuItemDel
			// 
			this->menuItemDel->Name = L"menuItemDel";
			this->menuItemDel->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->menuItemDel->Size = System::Drawing::Size(191, 22);
			this->menuItemDel->Text = L"删除（&L）";
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
			this->menuItemFind->Text = L"查找（&F）...";
			this->menuItemFind->Click += gcnew System::EventHandler(this, &MainForm::menuItemFind_Click);
			// 
			// menuItemFindNext
			// 
			this->menuItemFindNext->Name = L"menuItemFindNext";
			this->menuItemFindNext->ShortcutKeys = System::Windows::Forms::Keys::F3;
			this->menuItemFindNext->Size = System::Drawing::Size(191, 22);
			this->menuItemFindNext->Text = L"查找下一个（&N）";
			this->menuItemFindNext->Click += gcnew System::EventHandler(this, &MainForm::menuItemFindNext_Click);
			// 
			// menuItemReplace
			// 
			this->menuItemReplace->Name = L"menuItemReplace";
			this->menuItemReplace->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
			this->menuItemReplace->Size = System::Drawing::Size(191, 22);
			this->menuItemReplace->Text = L"替换（&R）...";
			this->menuItemReplace->Click += gcnew System::EventHandler(this, &MainForm::menuItemReplace_Click);
			// 
			// menuItemTo
			// 
			this->menuItemTo->Name = L"menuItemTo";
			this->menuItemTo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->menuItemTo->Size = System::Drawing::Size(191, 22);
			this->menuItemTo->Text = L"转到（&G）...";
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
			this->menuItemSelectAll->Text = L"全选（&A）";
			this->menuItemSelectAll->Click += gcnew System::EventHandler(this, &MainForm::menuItemSelectAll_Click);
			// 
			// menuItemDayTime
			// 
			this->menuItemDayTime->Name = L"menuItemDayTime";
			this->menuItemDayTime->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->menuItemDayTime->Size = System::Drawing::Size(191, 22);
			this->menuItemDayTime->Text = L"时间/日期（&D）";
			this->menuItemDayTime->Click += gcnew System::EventHandler(this, &MainForm::menuItemDayTime_Click);
			// 
			// menuItemFormat
			// 
			this->menuItemFormat->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuItemWrap, 
				this->menuItemfFont});
			this->menuItemFormat->Name = L"menuItemFormat";
			this->menuItemFormat->Size = System::Drawing::Size(78, 25);
			this->menuItemFormat->Text = L"格式（&O）";
			// 
			// menuItemWrap
			// 
			this->menuItemWrap->Checked = true;
			this->menuItemWrap->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menuItemWrap->Name = L"menuItemWrap";
			this->menuItemWrap->Size = System::Drawing::Size(160, 22);
			this->menuItemWrap->Text = L"自动换行（&W）";
			this->menuItemWrap->Click += gcnew System::EventHandler(this, &MainForm::menuItemWrap_Click);
			// 
			// menuItemfFont
			// 
			this->menuItemfFont->Name = L"menuItemfFont";
			this->menuItemfFont->Size = System::Drawing::Size(160, 22);
			this->menuItemfFont->Text = L"字体(&F)...";
			this->menuItemfFont->Click += gcnew System::EventHandler(this, &MainForm::menuItemfFont_Click);
			// 
			// menuItemView
			// 
			this->menuItemView->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->menuItemState});
			this->menuItemView->Name = L"menuItemView";
			this->menuItemView->Size = System::Drawing::Size(76, 25);
			this->menuItemView->Text = L"查看（&V）";
			// 
			// menuItemState
			// 
			this->menuItemState->Enabled = false;
			this->menuItemState->Name = L"menuItemState";
			this->menuItemState->Size = System::Drawing::Size(143, 22);
			this->menuItemState->Text = L"状态栏（&S）";
			// 
			// menuItemHelp
			// 
			this->menuItemHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuItemAboutTopic, 
				this->menuItemAbout});
			this->menuItemHelp->Name = L"menuItemHelp";
			this->menuItemHelp->Size = System::Drawing::Size(77, 25);
			this->menuItemHelp->Text = L"帮助（H）";
			// 
			// menuItemAboutTopic
			// 
			this->menuItemAboutTopic->Name = L"menuItemAboutTopic";
			this->menuItemAboutTopic->Size = System::Drawing::Size(152, 22);
			this->menuItemAboutTopic->Text = L"帮助主题(&H)";
			// 
			// menuItemAbout
			// 
			this->menuItemAbout->Name = L"menuItemAbout";
			this->menuItemAbout->Size = System::Drawing::Size(152, 22);
			this->menuItemAbout->Text = L"关于记事本(&A)";
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
			this->tlsbtnNew->ToolTipText = L"新建空白文档";
			this->tlsbtnNew->Click += gcnew System::EventHandler(this, &MainForm::menuItemNew_Click);
			// 
			// tlsbtnOpen
			// 
			this->tlsbtnOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnOpen.Image")));
			this->tlsbtnOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnOpen->Name = L"tlsbtnOpen";
			this->tlsbtnOpen->Size = System::Drawing::Size(23, 22);
			this->tlsbtnOpen->ToolTipText = L"打开";
			this->tlsbtnOpen->Click += gcnew System::EventHandler(this, &MainForm::menuItemOpen_Click);
			// 
			// tlsbtnSave
			// 
			this->tlsbtnSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnSave->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnSave.Image")));
			this->tlsbtnSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnSave->Name = L"tlsbtnSave";
			this->tlsbtnSave->Size = System::Drawing::Size(23, 22);
			this->tlsbtnSave->ToolTipText = L"保存";
			this->tlsbtnSave->Click += gcnew System::EventHandler(this, &MainForm::menuItemSave_Click);
			// 
			// tlsbtnPrint
			// 
			this->tlsbtnPrint->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnPrint->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnPrint.Image")));
			this->tlsbtnPrint->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnPrint->Name = L"tlsbtnPrint";
			this->tlsbtnPrint->Size = System::Drawing::Size(23, 22);
			this->tlsbtnPrint->Text = L"打印";
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
			this->tlsbtnCut->ToolTipText = L"剪切";
			this->tlsbtnCut->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
			// 
			// tlsbtnCopy
			// 
			this->tlsbtnCopy->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnCopy->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnCopy.Image")));
			this->tlsbtnCopy->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnCopy->Name = L"tlsbtnCopy";
			this->tlsbtnCopy->Size = System::Drawing::Size(23, 22);
			this->tlsbtnCopy->ToolTipText = L"复制";
			this->tlsbtnCopy->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
			// 
			// tlsbtnPaster
			// 
			this->tlsbtnPaster->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnPaster->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnPaster.Image")));
			this->tlsbtnPaster->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnPaster->Name = L"tlsbtnPaster";
			this->tlsbtnPaster->Size = System::Drawing::Size(23, 22);
			this->tlsbtnPaster->ToolTipText = L"粘贴";
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
			this->tlsbtnBold->ToolTipText = L"粗体";
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
			this->tlsbtnItalic->ToolTipText = L"斜体";
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
			this->tlsbtnUnderline->ToolTipText = L"下划线";
			this->tlsbtnUnderline->CheckedChanged += gcnew System::EventHandler(this, &MainForm::tlsbtnUnderline_CheckedChanged);
			// 
			// tlsbtnColor
			// 
			this->tlsbtnColor->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tlsbtnColor->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tlsbtnColor.Image")));
			this->tlsbtnColor->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tlsbtnColor->Name = L"tlsbtnColor";
			this->tlsbtnColor->Size = System::Drawing::Size(23, 22);
			this->tlsbtnColor->ToolTipText = L"字体颜色";
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
			this->txtBoxMain->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::pressEnterOnTextBox);
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
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->撤销ToolStripMenuItem, 
				this->toolStripSeparator3, this->剪切ToolStripMenuItem, this->复制CToolStripMenuItem, this->粘贴VToolStripMenuItem, this->删除DelToolStripMenuItem, 
				this->toolStripMenuItem5, this->全选AToolStripMenuItem, this->toolStripMenuItem6});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(144, 154);
			// 
			// 撤销ToolStripMenuItem
			// 
			this->撤销ToolStripMenuItem->Name = L"撤销ToolStripMenuItem";
			this->撤销ToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->撤销ToolStripMenuItem->Text = L"撤销（&U）";
			this->撤销ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemUndo_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(140, 6);
			// 
			// 剪切ToolStripMenuItem
			// 
			this->剪切ToolStripMenuItem->Name = L"剪切ToolStripMenuItem";
			this->剪切ToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->剪切ToolStripMenuItem->Text = L"剪切（&I）";
			this->剪切ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemCut_Click);
			// 
			// 复制CToolStripMenuItem
			// 
			this->复制CToolStripMenuItem->Name = L"复制CToolStripMenuItem";
			this->复制CToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->复制CToolStripMenuItem->Text = L"复制（&C）";
			this->复制CToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemCopy_Click);
			// 
			// 粘贴VToolStripMenuItem
			// 
			this->粘贴VToolStripMenuItem->Name = L"粘贴VToolStripMenuItem";
			this->粘贴VToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->粘贴VToolStripMenuItem->Text = L"粘贴（&V）";
			this->粘贴VToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemStick_Click);
			// 
			// 删除DelToolStripMenuItem
			// 
			this->删除DelToolStripMenuItem->Name = L"删除DelToolStripMenuItem";
			this->删除DelToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->删除DelToolStripMenuItem->Text = L"删除（Del）";
			this->删除DelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemDel_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(140, 6);
			// 
			// 全选AToolStripMenuItem
			// 
			this->全选AToolStripMenuItem->Name = L"全选AToolStripMenuItem";
			this->全选AToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->全选AToolStripMenuItem->Text = L"全选（&A）";
			this->全选AToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuItemSelectAll_Click);
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
			this->TipBox->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->TipBox->FormattingEnabled = true;
			this->TipBox->ItemHeight = 17;
			this->TipBox->Location = System::Drawing::Point(58, 77);
			this->TipBox->Name = L"TipBox";
			this->TipBox->Size = System::Drawing::Size(204, 123);
			this->TipBox->TabIndex = 3;
			this->TipBox->Visible = false;
			this->TipBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::pressEnterOnTipBox);
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
			this->Text = L"无标题—记事本";
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
			 this->openFileDialog1 ->Filter="文本文件(.txt)|*.txt|所有文件(*.*)|*.*";
			 try
			 {
			 if(this->openFileDialog1 ->ShowDialog ()==System::Windows ::Forms ::DialogResult ::OK )
			 {
			 String^ name = this->openFileDialog1 ->FileName ;
			this->Text = name +"-记事本";
			this->openFileDialog1 ->Title ="打开";
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
			 this->saveFileDialog1 ->Filter ="文本文件(.txt)|*.txt|所有文件(*.*)|*.*";
			 try 
			 {
				 File::WriteAllText (name,this->txtBoxMain ->Text );
			 }
			 catch(System::IO ::IOException^ ex)
			 {
				 MessageBox::Show ( ex->Message  , "记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
			   MessageBox::Show(ex->Message ,"记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
			 System::Windows ::Forms ::DialogResult result=Windows::Forms ::MessageBox ::Show ("文件"+this->Text +"已修改，是否要保存","记事本",MessageBoxButtons::YesNoCancel ,MessageBoxIcon::Exclamation )	;
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
				 System::Windows ::Forms ::MessageBox ::Show ("没有搜索到"+search->str ,"记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
				 System::Windows ::Forms ::MessageBox ::Show ("没有搜索到"+replace->strSearch    ,"记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
				 System::Windows ::Forms ::MessageBox ::Show ("没有搜索到"+search->str ,"记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
				        this->Text = name +"-记事本";
				        writer->Close();
				}
				}
				}
			  catch(System::IO ::IOException^ ex)
			 {
				 MessageBox::Show ( ex->Message  , "记事本",MessageBoxButtons::OK ,MessageBoxIcon::Exclamation );
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
			if(to->selectItem ="开头")
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
				 bool needSetTipBox = true;
				 if (m_nIndex == -1)
				 {
					 //如果没有开始记录，且当前位置之前是一个空格、换行\r、句号. 则开始记录
					 int cursorPos = this->txtBoxMain->SelectionStart;
					 if(cursorPos == 0 || cursorPos == 1)
						 m_nIndex = 0;
					 else
					 {
						 Char lastChar = text[cursorPos-1];
						 if (lastChar == ' ' || lastChar == '\n' || lastChar == '\r' || lastChar == '.' || lastChar == ',' || lastChar == ';')
						 {
							 m_nIndex = cursorPos;
						 }
					 }
				 }
				 else
				 {
					 //开始记录后，但是依旧遇到了空格等特殊字符，且当时没有listbox显示，则重新进行记录
					 if (TipBox->Enabled == false && TipBox->Visible == false)
					 {
						 //是不是真的没有匹配了
						 needSetTipBox = !SetTipBox(); 
						 if(needSetTipBox)
						 {
							 int cursorPos = this->txtBoxMain->SelectionStart;
							 if(cursorPos >= 1)
							 {
								 Char lastChar = text[cursorPos-1];
								 if (lastChar == ' ' || lastChar == '\n' || lastChar == '\r' || lastChar == '.' || lastChar == ',' || lastChar == ';')
								 {
									 m_nIndex = cursorPos;
								 }
							 }
						 }						 
					 }
				 }
				 if(needSetTipBox)
					SetTipBox();
			 }
			 
		 }
private: System::Void mouseDoubleClickOnTipBox(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 AddSelectString();
		 }
private: System::Void pressEnterOnTextBox(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab)
			 {
				 //按下回车或table，且处于选中列表时，写下选中项
				 if (TipBox->Enabled == true && TipBox->Visible == true && TipBox->SelectedIndex != -1)
				 {
					 AddSelectString();
					 //不要继续换行了
					 e->SuppressKeyPress = true;
				 }
			 }
			 else if (e->KeyCode ==  Keys::Up)
			 {
				 if(TipBox->SelectedIndex > 0)
					 TipBox->SelectedIndex--;
			 }
			 else if (e->KeyCode == Keys::Down)
			 {
				 if(TipBox->SelectedIndex < TipBox->Items->Count - 1)
					 TipBox->SelectedIndex++;
			 }
		 }
private: System::Void pressEnterOnTipBox(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 AddSelectString();
		 }

		 bool SetTipBox()
		 {
			 String^ text = this->txtBoxMain->Text;
			 if (m_nIndex < text->Length && m_nIndex >= 0)
			 {
				 String^ testString = text->Substring(m_nIndex);
				 TipBox->Items->Clear();
				 TipBox->BeginUpdate();
				 for (vector<String^>::iterator it=m_VDatabase.begin();it!=m_VDatabase.end();it++)
				 {
					 String^ matchString = *it;
					 matchString->ToUpper();
					 if(matchString->StartsWith(testString->ToUpper()))
					 {
						 if(TipBox->Enabled == false && TipBox->Visible == false)
						 {
							 TipBox->Enabled = true;
							 TipBox->Show();
						 }					 
						 TipBox->Items->Add(*it);
					 }
				 }
				 TipBox->EndUpdate();
				 if(TipBox->Items->Count > 0)
				 {
					 TipBox->SetSelected(0,true);
					 //移动位置
					 Point pos = this->txtBoxMain->GetPositionFromCharIndex(this->txtBoxMain->SelectionStart-1);
					 pos.X += 20;
					 pos.Y += 60;
					 TipBox->Location = pos;
					 return true;
				 }
				 else
				 {
					 TipBox->Hide();
					 TipBox->Enabled = false;
					 return false;
				 }
			 }	
			 else
			 {
				 if(m_nIndex >= text->Length)
					 m_nIndex = this->txtBoxMain->SelectionStart;
				 TipBox->Hide();
				 TipBox->Enabled = false;
				 return false;
			 }
		 }

		 void AddSelectString()
		 {
			 if (m_nIndex < this->txtBoxMain->Text->Length)
			 {		 
				 //首先需要标记此时是我人为控制textbox文本，禁止TextChanged处理
				 m_bNeedProcessTextChanged = false;

				 //先移除匹配的部分，然后接上选中的项
				 this->txtBoxMain->Text = this->txtBoxMain->Text->Substring(0,m_nIndex);
				 this->txtBoxMain->AppendText(TipBox->SelectedItem->ToString());

				 //重新让TextChanged有效
				 m_bNeedProcessTextChanged = true;

				 //重置记录器
				 //m_nIndex = -1;

				 //指向要修改的文本变量
				 Int32 flag = TipBox->SelectedItem->ToString()->IndexOf("$",0);
				 if (flag != -1)
				 {
					 Int32 tail = TipBox->SelectedItem->ToString()->IndexOf(" ",flag);
				 }

				 TipBox->Enabled = false;
				 TipBox->Hide();
			 }			 
		 }
};
  }