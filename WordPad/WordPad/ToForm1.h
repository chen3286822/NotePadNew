#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace WordPad {

	/// <summary>
	/// ToForm 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class ToForm : public System::Windows::Forms::Form
	{
	public:
		ToForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~ToForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdlbtnEnd;
	protected: 

	private: System::Windows::Forms::RadioButton^  rdlbtnStart;
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Button^  button2;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdlbtnEnd = (gcnew System::Windows::Forms::RadioButton());
			this->rdlbtnStart = (gcnew System::Windows::Forms::RadioButton());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdlbtnEnd);
			this->groupBox1->Controls->Add(this->rdlbtnStart);
			this->groupBox1->Location = System::Drawing::Point(26, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(233, 62);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"转到";
			// 
			// rdlbtnEnd
			// 
			this->rdlbtnEnd->AutoSize = true;
			this->rdlbtnEnd->Location = System::Drawing::Point(157, 30);
			this->rdlbtnEnd->Name = L"rdlbtnEnd";
			this->rdlbtnEnd->Size = System::Drawing::Size(47, 16);
			this->rdlbtnEnd->TabIndex = 1;
			this->rdlbtnEnd->TabStop = true;
			this->rdlbtnEnd->Text = L"末尾";
			this->rdlbtnEnd->UseVisualStyleBackColor = true;
			// 
			// rdlbtnStart
			// 
			this->rdlbtnStart->AutoSize = true;
			this->rdlbtnStart->Checked = true;
			this->rdlbtnStart->Location = System::Drawing::Point(35, 30);
			this->rdlbtnStart->Name = L"rdlbtnStart";
			this->rdlbtnStart->Size = System::Drawing::Size(47, 16);
			this->rdlbtnStart->TabIndex = 0;
			this->rdlbtnStart->TabStop = true;
			this->rdlbtnStart->Text = L"开头";
			this->rdlbtnStart->UseVisualStyleBackColor = true;
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(48, 85);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(60, 23);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"确定";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &ToForm::btnOK_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(183, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"取消";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ToForm::button2_Click);
			// 
			// ToForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(298, 120);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->groupBox1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ToForm";
			this->ShowIcon = false;
			this->Text = L"转到";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:String^ selectItem;
	private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
   public: String^ point()
	{
		if(this->rdlbtnStart ->Checked ==true)
		{
			selectItem = "开头";
		}
		else
		{
		   selectItem = "末尾";
		}
	    	return selectItem;
			}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close ();
		 }
};
}
