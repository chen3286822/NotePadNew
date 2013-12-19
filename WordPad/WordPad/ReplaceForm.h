#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace WordPad {

	/// <summary>
	/// ReplaceForm 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class ReplaceForm : public System::Windows::Forms::Form
	{
	public:
		ReplaceForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			
			FindPlace =0;
			lower=this->checkBoxLowerOrPower ->Checked ;
		    replaceAll = false;
			
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~ReplaceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtSearch;
	private: System::Windows::Forms::TextBox^  txtReplace;


	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::Button^  btnReplace;
	private: System::Windows::Forms::Button^  btnReplaceAll;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::CheckBox^  checkBoxLowerOrPower;





	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->txtReplace = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnReplace = (gcnew System::Windows::Forms::Button());
			this->btnReplaceAll = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->checkBoxLowerOrPower = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"查找内容(&N):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"替换内容(&P):";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(104, 9);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(178, 21);
			this->txtSearch->TabIndex = 2;
			// 
			// txtReplace
			// 
			this->txtReplace->Location = System::Drawing::Point(104, 40);
			this->txtReplace->Name = L"txtReplace";
			this->txtReplace->Size = System::Drawing::Size(178, 21);
			this->txtReplace->TabIndex = 3;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(298, 7);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(99, 23);
			this->btnSearch->TabIndex = 4;
			this->btnSearch->Text = L"查找下一个(&F)";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &ReplaceForm::btnSearch_Click);
			// 
			// btnReplace
			// 
			this->btnReplace->Location = System::Drawing::Point(298, 38);
			this->btnReplace->Name = L"btnReplace";
			this->btnReplace->Size = System::Drawing::Size(99, 23);
			this->btnReplace->TabIndex = 5;
			this->btnReplace->Text = L"替换(&R)";
			this->btnReplace->UseVisualStyleBackColor = true;
			this->btnReplace->Click += gcnew System::EventHandler(this, &ReplaceForm::btnReplace_Click);
			// 
			// btnReplaceAll
			// 
			this->btnReplaceAll->Location = System::Drawing::Point(298, 67);
			this->btnReplaceAll->Name = L"btnReplaceAll";
			this->btnReplaceAll->Size = System::Drawing::Size(99, 23);
			this->btnReplaceAll->TabIndex = 6;
			this->btnReplaceAll->Text = L"全部替换(&A)";
			this->btnReplaceAll->UseVisualStyleBackColor = true;
			this->btnReplaceAll->Click += gcnew System::EventHandler(this, &ReplaceForm::btnReplaceAll_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(298, 96);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(99, 23);
			this->btnCancel->TabIndex = 7;
			this->btnCancel->Text = L"取消";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &ReplaceForm::button4_Click);
			// 
			// checkBoxLowerOrPower
			// 
			this->checkBoxLowerOrPower->AutoSize = true;
			this->checkBoxLowerOrPower->Location = System::Drawing::Point(14, 113);
			this->checkBoxLowerOrPower->Name = L"checkBoxLowerOrPower";
			this->checkBoxLowerOrPower->Size = System::Drawing::Size(84, 16);
			this->checkBoxLowerOrPower->TabIndex = 8;
			this->checkBoxLowerOrPower->Text = L"区分大小写";
			this->checkBoxLowerOrPower->UseVisualStyleBackColor = true;
			// 
			// ReplaceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 164);
			this->Controls->Add(this->checkBoxLowerOrPower);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnReplaceAll);
			this->Controls->Add(this->btnReplace);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->txtReplace);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ReplaceForm";
			this->ShowIcon = false;
			this->Text = L"替换";
			this->Load += gcnew System::EventHandler(this, &ReplaceForm::ReplaceForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:String^ strSearch;
public:String^ strReplace;
public:int FindPlace;
 public:bool lower;
public:bool replaceAll;
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
                           this->Close ();	
		 }
private: System::Void btnReplace_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->txtReplace->Text ->Length >0 && this->txtSearch->Text ->Length >0)
			 {
			   this->strReplace =this->txtReplace ->Text ;
			   this->strSearch =this->txtSearch ->Text;
			 }
		
		 }

public:int Replace(String^ text)
	   {
		   if(text->Length >0)
			{
				 FindPlace = text->IndexOf (this->txtSearch ->Text ,FindPlace );
		         return FindPlace;
			}
	   }
private: System::Void ReplaceForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
           if(this->txtSearch ->Text !="")
			 {
				 strSearch =this->txtSearch ->Text ;

			 }
			
		 }
private: System::Void btnReplaceAll_Click(System::Object^  sender, System::EventArgs^  e) {
			  if(this->txtReplace->Text ->Length >0 && this->txtSearch->Text ->Length >0)
			 {
			   this->strReplace =this->txtReplace ->Text ;
			   this->strSearch =this->txtSearch ->Text ;
			 
			 }
		  replaceAll = true;
		 }
};
}
