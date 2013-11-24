/*
 * Author: Andreas Linde <mail@andreaslinde.de>
 *         Kent Sutherland
 *
 * Copyright (c) 2012-2013 HockeyApp, Bit Stadium GmbH.
 * Copyright (c) 2011 Andreas Linde & Kent Sutherland.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Cocoa/Cocoa.h>

@class BITCrashManager;

@interface BITCrashReportUI : NSWindowController {
  IBOutlet NSTextField  *nameTextField;
  IBOutlet NSTextField  *emailTextField;
  IBOutlet NSTextField  *descriptionTextField;
  IBOutlet NSTextView   *crashLogTextView;
  
  IBOutlet NSTextField  *nameTextFieldTitle;
  IBOutlet NSTextField  *emailTextFieldTitle;

  IBOutlet NSTextField  *introductionText;
  IBOutlet NSTextField  *commentsTextFieldTitle;
  IBOutlet NSTextField  *problemDescriptionTextFieldTitle;
  
  IBOutlet NSTextField  *noteText;
  
  IBOutlet NSButton   *disclosureButton;
  IBOutlet NSButton   *showButton;
  IBOutlet NSButton   *hideButton;
  IBOutlet NSButton   *cancelButton;
  IBOutlet NSButton   *submitButton;
  
  NSMenu              *_mainAppMenu;
  
  BITCrashManager   *_crashManager;
  
  NSString      *_companyName;
  NSString      *_applicationName;
  
  NSMutableString   *_logContent;
  NSString          *_userName;
  NSString          *_userEmail;
  NSString          *_crashLogContent;
  NSString          *_crashFile;
  
  BOOL showUserDetails;
  BOOL showComments;
  BOOL showDetails;
}

// defines the users name or user id
@property (nonatomic, retain) NSString *userName;

// defines the users email address
@property (nonatomic, retain) NSString *userEmail;


- (instancetype)initWithManager:(BITCrashManager *)crashManager crashReportFile:(NSString *)crashReportFile crashReport:(NSString *)crashReport logContent:(NSString *)logContent companyName:(NSString *)companyName applicationName:(NSString *)applicationName askUserDetails:(BOOL)askUserDetails;

- (void)askCrashReportDetails;

- (IBAction)cancelReport:(id)sender;
- (IBAction)submitReport:(id)sender;
- (IBAction)showDetails:(id)sender;
- (IBAction)hideDetails:(id)sender;
- (IBAction)showComments:(id)sender;

- (BOOL)showUserDetails;
- (void)setShowUserDetails:(BOOL)value;

- (BOOL)showComments;
- (void)setShowComments:(BOOL)value;

- (BOOL)showDetails;
- (void)setShowDetails:(BOOL)value;

@end