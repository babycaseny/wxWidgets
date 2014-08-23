/////////////////////////////////////////////////////////////////////////////
// Name:        wx/qt/dialog.h
// Author:      Peter Most, Javier Torres
// Copyright:   (c) Peter Most, Javier Torres
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_QT_DIALOG_H_
#define _WX_QT_DIALOG_H_

#include "wx/dialog.h"
#include "wx/qt/winevent_qt.h"
#include <QtWidgets/QDialog>

class WXDLLIMPEXP_CORE wxDialog : public wxDialogBase
{
public:
    wxDialog();
    wxDialog( wxWindow *parent, wxWindowID id,
            const wxString &title,
            const wxPoint &pos = wxDefaultPosition,
            const wxSize &size = wxDefaultSize,
            long style = wxDEFAULT_DIALOG_STYLE,
            const wxString &name = wxDialogNameStr );

    virtual ~wxDialog();
    
    bool Create( wxWindow *parent, wxWindowID id,
            const wxString &title,
            const wxPoint &pos = wxDefaultPosition,
            const wxSize &size = wxDefaultSize,
            long style = wxDEFAULT_DIALOG_STYLE,
            const wxString &name = wxDialogNameStr );

    virtual int ShowModal();
    virtual void EndModal(int retCode);
    virtual bool IsModal() const;

    virtual QDialog *GetHandle() const;

private:
    wxQtPointer< QDialog > m_qtDialog;

    wxDECLARE_DYNAMIC_CLASS_NO_COPY( wxDialog );
};


class WXDLLIMPEXP_CORE wxQtDialog : public wxQtEventSignalHandler< QDialog, wxDialog >
{
    Q_OBJECT

    public:
        wxQtDialog( wxWindow *parent, wxDialog *handler );
};

#endif // _WX_QT_DIALOG_H_