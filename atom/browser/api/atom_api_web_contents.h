// Copyright (c) 2014 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_ATOM_API_WEB_CONTENTS_H_
#define ATOM_BROWSER_API_ATOM_API_WEB_CONTENTS_H_

#include "atom/browser/api/event_emitter.h"
#include "native_mate/handle.h"

class GURL;

namespace content {
class WebContents;
}

namespace atom {

namespace api {

class WebContents : public mate::EventEmitter {
 public:
  static mate::Handle<WebContents> Create(v8::Isolate* isolate,
                                          content::WebContents* web_contents);

  GURL GetURL() const;
  string16 GetTitle() const;
  bool IsLoading() const;
  bool IsWaitingForResponse() const;
  void Stop();
  int GetRoutingID() const;
  int GetProcessID() const;
  bool IsCrashed() const;

 protected:
  explicit WebContents(content::WebContents* web_contents);
  virtual ~WebContents();

  // mate::Wrappable implementations:
  virtual mate::ObjectTemplateBuilder GetObjectTemplateBuilder(
      v8::Isolate* isolate);

 private:
  content::WebContents* web_contents_;  // Weak.

  DISALLOW_COPY_AND_ASSIGN(WebContents);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_BROWSER_API_ATOM_API_WEB_CONTENTS_H_
