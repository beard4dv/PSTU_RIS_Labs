#pragma once
#include "tree.h"

namespace TreeLabWinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			buttonEnable(false);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Tree* tree;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:
	private: System::Windows::Forms::Button^ clearRTB1;
	private: System::Windows::Forms::Button^ createTree;

	private: System::Windows::Forms::Button^ printTree;
	private: System::Windows::Forms::Button^ deleteNode;
	private: System::Windows::Forms::TextBox^ delTextBox;

	private: System::Windows::Forms::Button^ insertNode;
	private: System::Windows::Forms::TextBox^ insTextBox;
	private: System::Windows::Forms::Button^ findElement;
	private: System::Windows::Forms::TextBox^ findTextBox;
	private: System::Windows::Forms::Button^ balanceTree;
	private: System::Windows::Forms::Button^ preOrder;
	private: System::Windows::Forms::Button^ inOrder;
	private: System::Windows::Forms::Button^ postOrder;
	private: System::Windows::Forms::Button^ printVTree;
	private: System::Windows::Forms::Button^ visTree;
	private: System::Windows::Forms::Button^ fillTree;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ createtextBox;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->clearRTB1 = (gcnew System::Windows::Forms::Button());
			this->createTree = (gcnew System::Windows::Forms::Button());
			this->printTree = (gcnew System::Windows::Forms::Button());
			this->deleteNode = (gcnew System::Windows::Forms::Button());
			this->delTextBox = (gcnew System::Windows::Forms::TextBox());
			this->insertNode = (gcnew System::Windows::Forms::Button());
			this->insTextBox = (gcnew System::Windows::Forms::TextBox());
			this->findElement = (gcnew System::Windows::Forms::Button());
			this->findTextBox = (gcnew System::Windows::Forms::TextBox());
			this->balanceTree = (gcnew System::Windows::Forms::Button());
			this->preOrder = (gcnew System::Windows::Forms::Button());
			this->inOrder = (gcnew System::Windows::Forms::Button());
			this->postOrder = (gcnew System::Windows::Forms::Button());
			this->printVTree = (gcnew System::Windows::Forms::Button());
			this->visTree = (gcnew System::Windows::Forms::Button());
			this->fillTree = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->createtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(290, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(432, 408);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// clearRTB1
			// 
			this->clearRTB1->Location = System::Drawing::Point(290, 426);
			this->clearRTB1->Name = L"clearRTB1";
			this->clearRTB1->Size = System::Drawing::Size(432, 23);
			this->clearRTB1->TabIndex = 1;
			this->clearRTB1->Text = L"Clear";
			this->clearRTB1->UseVisualStyleBackColor = true;
			this->clearRTB1->Click += gcnew System::EventHandler(this, &MyForm::clearRTB1_Click);
			// 
			// createTree
			// 
			this->createTree->Location = System::Drawing::Point(6, 19);
			this->createTree->Name = L"createTree";
			this->createTree->Size = System::Drawing::Size(127, 23);
			this->createTree->TabIndex = 2;
			this->createTree->Text = L"Create Tree";
			this->createTree->UseVisualStyleBackColor = true;
			this->createTree->Click += gcnew System::EventHandler(this, &MyForm::createTree_Click);
			// 
			// printTree
			// 
			this->printTree->Location = System::Drawing::Point(6, 19);
			this->printTree->Name = L"printTree";
			this->printTree->Size = System::Drawing::Size(120, 23);
			this->printTree->TabIndex = 3;
			this->printTree->Text = L"Print Tree";
			this->printTree->UseVisualStyleBackColor = true;
			this->printTree->Click += gcnew System::EventHandler(this, &MyForm::printTree_Click);
			// 
			// deleteNode
			// 
			this->deleteNode->Location = System::Drawing::Point(6, 77);
			this->deleteNode->Name = L"deleteNode";
			this->deleteNode->Size = System::Drawing::Size(127, 23);
			this->deleteNode->TabIndex = 4;
			this->deleteNode->Text = L"Delete Node";
			this->deleteNode->UseVisualStyleBackColor = true;
			this->deleteNode->Click += gcnew System::EventHandler(this, &MyForm::deleteNode_Click);
			// 
			// delTextBox
			// 
			this->delTextBox->Location = System::Drawing::Point(139, 79);
			this->delTextBox->Name = L"delTextBox";
			this->delTextBox->Size = System::Drawing::Size(32, 20);
			this->delTextBox->TabIndex = 5;
			this->delTextBox->Text = L"0";
			// 
			// insertNode
			// 
			this->insertNode->Location = System::Drawing::Point(6, 48);
			this->insertNode->Name = L"insertNode";
			this->insertNode->Size = System::Drawing::Size(127, 23);
			this->insertNode->TabIndex = 6;
			this->insertNode->Text = L"Insert Node";
			this->insertNode->UseVisualStyleBackColor = true;
			this->insertNode->Click += gcnew System::EventHandler(this, &MyForm::insertNode_Click);
			// 
			// insTextBox
			// 
			this->insTextBox->Location = System::Drawing::Point(139, 50);
			this->insTextBox->Name = L"insTextBox";
			this->insTextBox->Size = System::Drawing::Size(32, 20);
			this->insTextBox->TabIndex = 7;
			this->insTextBox->Text = L"0";
			// 
			// findElement
			// 
			this->findElement->Location = System::Drawing::Point(18, 184);
			this->findElement->Name = L"findElement";
			this->findElement->Size = System::Drawing::Size(127, 23);
			this->findElement->TabIndex = 8;
			this->findElement->Text = L"Find Element";
			this->findElement->UseVisualStyleBackColor = true;
			this->findElement->Click += gcnew System::EventHandler(this, &MyForm::findElement_Click);
			// 
			// findTextBox
			// 
			this->findTextBox->Location = System::Drawing::Point(151, 184);
			this->findTextBox->Name = L"findTextBox";
			this->findTextBox->Size = System::Drawing::Size(32, 20);
			this->findTextBox->TabIndex = 9;
			this->findTextBox->Text = L"0";
			// 
			// balanceTree
			// 
			this->balanceTree->Location = System::Drawing::Point(6, 135);
			this->balanceTree->Name = L"balanceTree";
			this->balanceTree->Size = System::Drawing::Size(127, 23);
			this->balanceTree->TabIndex = 10;
			this->balanceTree->Text = L"Balance Tree";
			this->balanceTree->UseVisualStyleBackColor = true;
			this->balanceTree->Click += gcnew System::EventHandler(this, &MyForm::balanceTree_Click);
			// 
			// preOrder
			// 
			this->preOrder->Location = System::Drawing::Point(6, 19);
			this->preOrder->Name = L"preOrder";
			this->preOrder->Size = System::Drawing::Size(120, 23);
			this->preOrder->TabIndex = 11;
			this->preOrder->Text = L"Direct Order";
			this->preOrder->UseVisualStyleBackColor = true;
			this->preOrder->Click += gcnew System::EventHandler(this, &MyForm::preOrder_Click);
			// 
			// inOrder
			// 
			this->inOrder->Location = System::Drawing::Point(134, 19);
			this->inOrder->Name = L"inOrder";
			this->inOrder->Size = System::Drawing::Size(120, 23);
			this->inOrder->TabIndex = 12;
			this->inOrder->Text = L"Symmetrical Order";
			this->inOrder->UseVisualStyleBackColor = true;
			this->inOrder->Click += gcnew System::EventHandler(this, &MyForm::inOrder_Click);
			// 
			// postOrder
			// 
			this->postOrder->Location = System::Drawing::Point(6, 48);
			this->postOrder->Name = L"postOrder";
			this->postOrder->Size = System::Drawing::Size(120, 23);
			this->postOrder->TabIndex = 13;
			this->postOrder->Text = L"Reverse Order";
			this->postOrder->UseVisualStyleBackColor = true;
			this->postOrder->Click += gcnew System::EventHandler(this, &MyForm::postOrder_Click);
			// 
			// printVTree
			// 
			this->printVTree->Location = System::Drawing::Point(134, 19);
			this->printVTree->Name = L"printVTree";
			this->printVTree->Size = System::Drawing::Size(120, 23);
			this->printVTree->TabIndex = 14;
			this->printVTree->Text = L"Print Vertical Tree";
			this->printVTree->UseVisualStyleBackColor = true;
			this->printVTree->Click += gcnew System::EventHandler(this, &MyForm::printVTree_Click);
			// 
			// visTree
			// 
			this->visTree->Location = System::Drawing::Point(11, 362);
			this->visTree->Name = L"visTree";
			this->visTree->Size = System::Drawing::Size(260, 23);
			this->visTree->TabIndex = 15;
			this->visTree->Text = L"Tree Visualization";
			this->visTree->UseVisualStyleBackColor = true;
			this->visTree->Click += gcnew System::EventHandler(this, &MyForm::visTree_Click);
			// 
			// fillTree
			// 
			this->fillTree->Location = System::Drawing::Point(6, 106);
			this->fillTree->Name = L"fillTree";
			this->fillTree->Size = System::Drawing::Size(127, 23);
			this->fillTree->TabIndex = 16;
			this->fillTree->Text = L"Fill Tree";
			this->fillTree->UseVisualStyleBackColor = true;
			this->fillTree->Click += gcnew System::EventHandler(this, &MyForm::fillTree_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->createtextBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->insTextBox);
			this->groupBox1->Controls->Add(this->insertNode);
			this->groupBox1->Controls->Add(this->delTextBox);
			this->groupBox1->Controls->Add(this->fillTree);
			this->groupBox1->Controls->Add(this->deleteNode);
			this->groupBox1->Controls->Add(this->createTree);
			this->groupBox1->Controls->Add(this->balanceTree);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(259, 166);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Edit Tree";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(177, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"№ first node";
			// 
			// createtextBox
			// 
			this->createtextBox->Location = System::Drawing::Point(139, 21);
			this->createtextBox->Name = L"createtextBox";
			this->createtextBox->Size = System::Drawing::Size(32, 20);
			this->createtextBox->TabIndex = 17;
			this->createtextBox->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(177, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"№ node";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(177, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"№ node";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(189, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"№ node";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->printTree);
			this->groupBox2->Controls->Add(this->printVTree);
			this->groupBox2->Location = System::Drawing::Point(12, 213);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(260, 51);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Print";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->inOrder);
			this->groupBox3->Controls->Add(this->preOrder);
			this->groupBox3->Controls->Add(this->postOrder);
			this->groupBox3->Location = System::Drawing::Point(12, 276);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(259, 80);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Order";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 461);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->findTextBox);
			this->Controls->Add(this->findElement);
			this->Controls->Add(this->visTree);
			this->Controls->Add(this->clearRTB1);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Tree";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createTree_Click(System::Object^ sender, System::EventArgs^ e) {
		tree = new Tree(Convert::ToDouble(this->createtextBox->Text));
		buttonEnable(true);
		this->richTextBox1->AppendText("Tree Created.\n");
	}
	private: System::Void printTree_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tree == nullptr)
		{
			this->richTextBox1->AppendText("[Error] No tree.\n");
			return;
		}
		this->richTextBox1->AppendText("____________________________________________________________\n\n");
		this->tree->printTree(1, this->richTextBox1);
		this->richTextBox1->AppendText("____________________________________________________________\n");
	}
	private: System::Void deleteNode_Click(System::Object^ sender, System::EventArgs^ e) {
		double node = Convert::ToDouble(this->delTextBox->Text);
		if (this->tree->getLeft() == NULL && this->tree->getRight() == NULL && this->tree->findElement(node) == tree)
		{
			delete tree;
			buttonEnable(false);
			this->richTextBox1->AppendText("Tree removed.\n");
			return;
		}
		this->tree->deleteNode(node, this->richTextBox1);
	}
	private: System::Void clearRTB1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->richTextBox1->Clear();
	}
	private: System::Void insertNode_Click(System::Object^ sender, System::EventArgs^ e) {
		double node = Convert::ToDouble(this->insTextBox->Text);
		this->tree->insertNode(node);
	}
	private: System::Void findElement_Click(System::Object^ sender, System::EventArgs^ e) {
		double node = Convert::ToDouble(this->findTextBox->Text);
		if (this->tree->findElement(node) != 0)
			richTextBox1->AppendText("Элемент " + Convert::ToString(node) + " найден.\n");
		else
			richTextBox1->AppendText("Элемент " + Convert::ToString(node) + " не найден.\n");
	}
	private: System::Void balanceTree_Click(System::Object^ sender, System::EventArgs^ e) {
		this->tree = this->tree->balancedTree(this->richTextBox1);
		this->richTextBox1->AppendText("\nДерево сбалансировано.\n");
	}
	private: System::Void preOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->AppendText("Direct Order: ");
		this->tree->preOrder(tree, this->richTextBox1);
		richTextBox1->AppendText("\n");
	}
	private: System::Void inOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->AppendText("Symmetrical order: ");
		this->tree->inOrder(tree, this->richTextBox1);
		richTextBox1->AppendText("\n");
	}
	private: System::Void postOrder_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->AppendText("Reverse order: ");
		this->tree->postOrder(tree, this->richTextBox1);
		richTextBox1->AppendText("\n");
	}
	private: System::Void printVTree_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tree == nullptr)
		{
			this->richTextBox1->AppendText("[Error] No tree.\n");
			return;
		}
		this->richTextBox1->AppendText("____________________________________________________________\n\n");
		this->tree->printVTree(2, this->richTextBox1);
		this->richTextBox1->AppendText("____________________________________________________________\n");
	}
	private: System::Void visTree_Click(System::Object^ sender, System::EventArgs^ e) {
		sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::White);
			this->tree->drawTree(window, tree, 400, 50, 150);
			window.display();
		}
	}
	private: System::Void fillTree_Click(System::Object^ sender, System::EventArgs^ e) {
		this->tree->insertNode(1.1);
		this->tree->insertNode(3.3);
		this->tree->insertNode(6.6);
		this->tree->insertNode(4.4);
		this->tree->insertNode(7.7);
		this->tree->insertNode(1.1);
	}
	void buttonEnable(bool enabled)
	{
		fillTree->Enabled = enabled;
		insertNode->Enabled = enabled;
		deleteNode->Enabled = enabled;
		findElement->Enabled = enabled;
		balanceTree->Enabled = enabled;
		printTree->Enabled = enabled;
		printVTree->Enabled = enabled;
		preOrder->Enabled = enabled;
		inOrder->Enabled = enabled;
		postOrder->Enabled = enabled;
		visTree->Enabled = enabled;
	}
};
}
