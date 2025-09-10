#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class DocumentElement{
    public:
        virtual string render() = 0;
};

class ImageElement : public DocumentElement
{
private:
    string imgPath;

public:
    ImageElement(string imgPath)
    {
        this->imgPath = imgPath;
    }
    string render()override{
        return imgPath;
    }
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class NewLineElement : public DocumentElement
{

public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};


class Document{
    private:
        vector<DocumentElement *> documentElements;
    public:
     void addElement(DocumentElement*element){
         documentElements.push_back(element);
     }

     string render(){
         string result;

         for(auto element:documentElements){
             result += element->render();
         }
         return result;
     }
};

class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage:public Persistence{
    public:
    void save(string data)override{
        ofstream outFile("document.txt");
         if(outFile){
             outFile << data;
             outFile.close();
             cout << "Document saved to document.txt" << endl;
         }
         else
         {
             cout << "Error : Unable to open file for writing." << endl;
         }  
    }
};

class DocumentEditor{
    private:
        Document *document;
        Persistence *storage;
        string renderedDocument;
    
    public:
         DocumentEditor(Document*document,Persistence*storage){
            this->document=document;
            this->storage = storage;
         }

         void addText(string text){
             document->addElement(new TextElement(text));
         }
         void addImage(string imgPath){
             document->addElement(new ImageElement(imgPath));
         }
         void addNewLine()
         {
             document->addElement(new NewLineElement());
         }
         void addTabSpace()
         {
             document->addElement(new TabSpaceElement());
         }

         string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
         }

         void saveDocument(){
             storage->save(renderDocument());
         }

};

int main(){
    Document *document = new Document();
    Persistence *persistence = new FileStorage();
    DocumentEditor *editor = new DocumentEditor(document, persistence);
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();
    return 0;
}