#include <search_list.h>

searchlist::searchlist(QWidget *parent, vector<string> t, int x, int y): QListWidget(parent), organization(t){
    text = new input(parent);
    text->move(x, y);
    text->show();
    this->resize(0,0);
    connect(text, SIGNAL(textChanged()), this, SLOT(load_list()));
    connect(text, SIGNAL(getfocus()), this, SLOT(load_list()));
    connect(text, SIGNAL(losefocus()), this, SLOT(focus_detect()));
    connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(testOnDoubleClicked(QListWidgetItem *)));
    this->move(x, y + 20);
    this->show();
};

void searchlist::load_list(){
    this->clear();
    vector<int> *t = lcs_1(organization, text->toPlainText().toStdString());
    int i = 0;
    while(t->at(i) != -1){
        this->addItem(organization.at(t->at(i)).c_str());
        this->item(i++);
    }
    this->setResizeMode(Adjust);
    if(i == 1){
        if(organization.at(t->at(i-1)) == text->toPlainText().toStdString())
            this->resize(0,0);
        else
            this->resize(200, 21);
    }
    else if(i <= 7){
        this->resize(200, i*21);
    }else{
        this->resize(200, 140);
    }
}
int searchlist::lcs_2(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    int result = 0;     //记录最长公共子串长度
    vector<vector<int>> c(len1 + 1, vector<int>(len2 + 1, 0));
    vector<vector<int>> vec(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                vec[i][j] = 0;
                result = c[i][j] > result ? c[i][j] : result;
            }
            else {
                c[i][j] = 0;
            }
        }
    }
    return result/3;
}

vector<int>* searchlist::lcs_1(vector<string> vs, string str){
    int max = 1, temp, t = -1;
    vector<int> *count = new vector<int>(25, -1);
    for(int i = 0; i < 33; i++)
        if((temp = lcs_2(vs.at(i), str)) > max){
            delete count;
            vector<int> *count = new vector<int>(25, -1);
            count->at(t = 0) = i;
            max = temp;
        }else if(temp == max){
            count->at(++t) = i;
        }
    return count;
}

void searchlist::testOnDoubleClicked(QListWidgetItem *item){
    text->setText(item->text());
}

void searchlist::focus_detect(){
    if(focus == 0 && text->focus == 0)
        out_focus();
    else
        load_list();
}

void searchlist::out_focus(){
    this->clear();
    this->resize(0, 0);
}

void searchlist::enterEvent(QEvent *ev)
{
    this->focus = 1;
}

void searchlist::leaveEvent(QEvent *ev)
{
    this->focus = 0;
    QTimer::singleShot(100, this, SLOT(focus_detect()));
}
