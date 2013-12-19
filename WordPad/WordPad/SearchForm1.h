#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace WordPad {

	/// <summary>
	/// SearchForm ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public:
		SearchForm(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			
			FindPlace =0;
			lower = this->checkBoxLowerOrPower ->Checked ;
			str= this->txtSearch ->Text ;
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtSearch;
	private: System::Windows::Forms::Button^  btnSearchNext;
	private: System::Windows::Forms::CheckBox^  checkBoxLowerOrPower;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdlbtnDown;
	private: System::Windows::Forms::RadioButton^  rdlbtnUp;
	private: System::Windows::Forms::Button^  btnCancel;
	protected: 

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearchNext = (gcnew System::Windows::Forms::Button());
			this->checkBoxLowerOrPower = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdlbtnDown = (gcnew System::Windows::Forms::RadioButton());
			this->rdlbtnUp = (gcnew System::Windows::Forms::RadioButton());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���ҵ����ݣ�&N����";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(121, 12);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(168, 21);
			this->txtSearch->TabIndex = 1;
			// 
			// btnSearchNext
			// 
			this->btnSearchNext->Location = System::Drawing::Point(310, 10);
			this->btnSearchNext->Name = L"btnSearchNext";
			this->btnSearchNext->Size = System::Drawing::Size(93, 23);
			this->btnSearchNext->TabIndex = 2;
			this->btnSearchNext->Text = L"������һ��(&F)";
			this->btnSearchNext->UseVisualStyleBackColor = true;
			this->btnSearchNext->Click += gcnew System::EventHandler(this, &SearchForm::btnSearchNext_Click);
			// 
			// checkBoxLowerOrPower
			// 
			this->checkBoxLowerOrPower->AutoSize = true;
			this->checkBoxLowerOrPower->Location = System::Drawing::Point(14, 56);
			this->checkBoxLowerOrPower->Name = L"checkBoxLowerOrPower";
			this->checkBoxLowerOrPower->Size = System::Drawing::Size(103, 16);
			this->checkBoxLowerOrPower->TabIndex = 3;
			this->checkBoxLowerOrPower->Text = L"���ִ�Сд(&C)";
			this->checkBoxLowerOrPower->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdlbtnDown);
			this->groupBox1->Controls->Add(this->rdlbtnUp);
			this->groupBox1->Location = System::Drawing::Point(143, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(146, 42);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"����";
			// 
			// rdlbtnDown
			// 
			this->rdlbtnDown->AutoSize = true;
			this->rdlbtnDown->Checked = true;
			this->rdlbtnDown->Location = System::Drawing::Point(78, 17);
			this->rdlbtnDown->Name = L"rdlbtnDown";
			this->rdlbtnDown->Size = System::Drawing::Size(65, 16);
			this->rdlbtnDown->TabIndex = 1;
			this->rdlbtnDown->TabStop = true;
			this->rdlbtnDown->Text = L"����(D)";
			this->rdlbtnDown->UseVisualStyleBackColor = true;
			// 
			// rdlbtnUp
			// 
			this->rdlbtnUp->AutoSize = true;
			this->rdlbtnUp->Location = System::Drawing::Point(7, 17);
			this->rdlbtnUp->Name = L"rdlbtnUp";
			this->rdlbtnUp->Size = System::Drawing::Size(65, 16);
			this->rdlbtnUp->TabIndex = 0;
			this->rdlbtnUp->Text = L"����(&U)";
			this->rdlbtnUp->UseVisualStyleBackColor = true;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(310, 39);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(93, 21);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"ȡ��";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &SearchForm::btnCancel_Click);
			// 
			// SearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 93);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->checkBoxLowerOrPower);
			this->Controls->Add(this->btnSearchNext);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SearchForm";
			this->ShowIcon = false;
			this->Text = L"����";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public :String^ str;
public:int FindPlace ;
 public:bool lower;
		
private: System::Void btnSearchNext_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(this->txtSearch ->Text !="")
			 {
				 str = Convert::ToString (this->txtSearch ->Text );

			 }
			 else 
			 {
			 this->btnSearchNext ->Enabled =false;
			} 
		 }

private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close ();
		 }
public: int find(String^ text)
		{
		
			if(text->Length >0)
		{
		  FindPlace = text->IndexOf (this->txtSearch ->Text,FindPlace );
		  return FindPlace;
		}
		
		}
};
}

//
