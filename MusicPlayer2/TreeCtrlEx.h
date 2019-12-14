#pragma once
#include <functional>


// CTreeCtrlEx

class CTreeCtrlEx : public CTreeCtrl
{
	DECLARE_DYNAMIC(CTreeCtrlEx)

public:
	CTreeCtrlEx();
	virtual ~CTreeCtrlEx();

public:
    void InsertPath(CString path, HTREEITEM hRoot);

    //向树中插入一个文件夹结构
    //path: 文件夹的根目录
    //hRoot: 要插入的根目录在树控件中的位置
    //is_path_show: 一个函数对象，用于判断一个文件夹是否需要显示
    void InsertPath(CString path, HTREEITEM hRoot, std::function<bool(const CString&)> is_path_show);
    CString GetItemPath(HTREEITEM hItem);

    void ExpandAll(HTREEITEM hItem);        //展开指定节点下的所有节点
    void ExpandAll();                       //展开所有节点
    void IterateItems(HTREEITEM hRoot, std::function<void(HTREEITEM)> func);           //遍历指定节点下的所有节点

    void SaveExpandState();                 //保存所有节点的展开收缩状态
    void SaveItemExpandState(HTREEITEM hItem, bool expand);     //保存指定节点的展开收缩状态
    void RestoreExpandState();              //恢复所有节点的展开收缩状态

protected:
    static std::map<CString, bool> m_expand_state;       //保存每个节点的展开收起状态

private:
    void _InsertPath(CString path, HTREEITEM hRoot, std::function<bool(const CString&)> is_path_show = [](const CString&) {return true; });

protected:
	DECLARE_MESSAGE_MAP()
    virtual void PreSubclassWindow();
};


