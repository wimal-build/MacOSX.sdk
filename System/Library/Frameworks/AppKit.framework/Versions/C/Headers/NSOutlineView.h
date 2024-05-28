/*
    NSOutlineView.h
    Application Kit
    Copyright (c) 1997-2012, Apple Inc.
    All rights reserved.
*/

#import <AppKit/NSTableView.h>
#import <AppKit/AppKitDefines.h>
#import <CoreFoundation/CFDictionary.h>

@class NSButtonCell;
@class NSTableView;
@class NSTableHeaderView;
@class NSTableColumn;
@class NSMouseTracker;
@class NSNotification;
@class NSString;
@protocol NSOutlineViewDelegate, NSOutlineViewDataSource;

typedef struct __OvFlags {
#ifdef __BIG_ENDIAN__
    unsigned int delegateWillDisplayCell:1;
    unsigned int delegateShouldEditTableColumn:1;
    unsigned int delegateShouldSelectItem:1;
    unsigned int delegateShouldSelectTableColumn:1;
    unsigned int delegateSelectionShouldChangeInOutlineView:1;
    unsigned int delegateShouldCollapseItem:1;
    unsigned int delegateShouldExpandItem:1;
    unsigned int autoresizesOutlineColumn:1;
    unsigned int autoSaveExpandItems:1;
    unsigned int enableExpandNotifications:1;
    unsigned int delegateWillDisplayOutlineCell:1;
    unsigned int subclassRowForItem:1;
    unsigned int selectionAdjustmentDisabled:1;
    unsigned int autoExpandFlashState:1;
    unsigned int animateExpandAndCollapse:1;
    unsigned int delegateHeightOfRowByItem:1;
    unsigned int delayRowEntryFreeDisabled:1;
    unsigned int numberOfRowsDataExpandEntered:1;
    unsigned int validDataSourceMethods:1;
    unsigned int reloadingData:1;
    unsigned int dataSourceDraggingEndedAt:1;
    unsigned int dataSourceDraggedImageMovedTo:1;
    unsigned int delegateShouldShowOutlineCellForItem:1;
    unsigned int delegateAutoExpandItem:1;
    unsigned int delegateAutoCollapseItem:1;
    unsigned int delegateShouldAutoExpandItem:1;
    unsigned int flashingEntireRow:1;
    unsigned int flashingOutlineCell:1;
    unsigned int dontRedisplayOnFrameChange:1;
    unsigned int allowAutomaticAnimations:1;
    unsigned int dataSourceObjectValueByItem:1;
    unsigned int allItemsLoaded:1;
#else
    unsigned int allItemsLoaded:1;
    unsigned int dataSourceObjectValueByItem:1;
    unsigned int allowAutomaticAnimations:1;
    unsigned int dontRedisplayOnFrameChange:1;
    unsigned int flashingOutlineCell:1;
    unsigned int flashingEntireRow:1;
    unsigned int delegateShouldAutoExpandItem:1;
    unsigned int delegateAutoCollapseItem:1;
    unsigned int delegateAutoExpandItem:1;
    unsigned int delegateShouldShowOutlineCellForItem:1;
    unsigned int dataSourceDraggedImageMovedTo:1;
    unsigned int dataSourceDraggingEndedAt:1;
    unsigned int reloadingData:1;
    unsigned int validDataSourceMethods:1;
    unsigned int numberOfRowsDataExpandEntered:1;
    unsigned int delayRowEntryFreeDisabled:1;
    unsigned int delegateHeightOfRowByItem:1;
    unsigned int animateExpandAndCollapse:1;
    unsigned int autoExpandFlashState:1;
    unsigned int selectionAdjustmentDisabled:1;
    unsigned int subclassRowForItem:1;
    unsigned int delegateWillDisplayOutlineCell:1;
    unsigned int enableExpandNotifications:1;
    unsigned int autoSaveExpandItems:1;
    unsigned int autoresizesOutlineColumn:1;
    unsigned int delegateShouldExpandItem:1;
    unsigned int delegateShouldCollapseItem:1;
    unsigned int delegateSelectionShouldChangeInOutlineView:1;
    unsigned int delegateShouldSelectTableColumn:1;
    unsigned int delegateShouldSelectItem:1;
    unsigned int delegateShouldEditTableColumn:1;
    unsigned int delegateWillDisplayCell:1;
#endif
} _OVFlags;

/* NSOutlineViewDropOnItemIndex may be used as a valid childIndex of a drop target item. In this case, the drop will happen directly on the target item.
*/
enum { NSOutlineViewDropOnItemIndex = -1 };

@class _NSOVRowEntry;

@interface NSOutlineView : NSTableView {
  @private
    NSInteger                                 _numberOfRows;    
    _NSOVRowEntry       *_rowEntryTree;
    NSMapTable          *_itemToEntryMap;
    __strong CFMutableArrayRef _rowEntryArray;
    NSInteger            _firstRowIndexDrawn;
    id                   _autoExpandTimerItem;
    NSTableColumn                *_outlineTableColumn;
    BOOL                 _initedRows;
    BOOL                                 _indentationMarkerInCell;
    NSInteger                                 _indentationPerLevel;
    NSButtonCell                       *_outlineCell;
    NSRect                                 _trackingOutlineFrame;
    id                   _expandingItem;
    NSInteger                                 _unused;
    _OVFlags                                 _ovFlags;
    id                                                 _ovLock;
    __strong long       *_indentArray;
    long                                 _originalWidth;
    id                                                 _expandSet;
    id                                                 _expandSetToExpandItemsInto;
    long                                        _indentArraySize;
    NSButtonCell        *_trackingOutlineCell;
    NSInteger            _trackingRow;
    id                   _ovReserved;
}

- (void)setDelegate:(id <NSOutlineViewDelegate>)anObject;
- (id <NSOutlineViewDelegate>)delegate;

- (void)setDataSource:(id <NSOutlineViewDataSource>)aSource;
- (id <NSOutlineViewDataSource>)dataSource;

/* The 'outlineTableColumn' is the column that displays data in a hierarchical fashion, indented one identationlevel per level, decorated with indentation marker (disclosure triangle) on rows that are expandable. A nil 'outlineTableColumn' is silently ignored. On 10.5 and higher, this value is saved in encodeWithCoder: and restored in initWithCoder:.
*/
- (void)setOutlineTableColumn:(NSTableColumn *)outlineTableColumn;
- (NSTableColumn *)outlineTableColumn;

/* Returns YES if 'item' is expandable and can contain other items. May call out to the delegate, if required. 
*/
- (BOOL)isExpandable:(id)item;

/* Expands 'item', if not already expanded, and all children if 'expandChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will expand  each item under the root. 
*/
- (void)expandItem:(id)item expandChildren:(BOOL)expandChildren;

/* Calls expandItem:expandChildren with 'expandChildren == NO' 
*/
- (void)expandItem:(id)item;

/* Collapses 'item' and all children if 'collapseChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will collapse each item under the root. 
*/
- (void)collapseItem:(id)item collapseChildren:(BOOL)collapseChildren;

/* Calls collapseItem:collapseChildren with 'collapseChildren == NO' 
*/
- (void)collapseItem:(id)item;

/* Reloads 'item' and all children if 'reloadChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will reload everything under the root item.
*/
- (void)reloadItem:(id)item reloadChildren:(BOOL)reloadChildren;

/* Calls reloadItem:reloadChildren with 'reloadChildren == NO' 
*/
- (void)reloadItem:(id)item;

/* Returns the parent for 'item', or nil, if the parent is the root. Available in 10.4 and higher.
*/
- (id)parentForItem:(id)item;

/* Item/Row translation
*/
- (id)itemAtRow:(NSInteger)row;
- (NSInteger)rowForItem:(id)item;

/* Indentation
*/
- (NSInteger)levelForItem:(id)item;
- (NSInteger)levelForRow:(NSInteger)row;
- (BOOL)isItemExpanded:(id)item;

/* Controls the amount of indentation per level. Negative values are ignored, and only integral values are accepted. The default value is 16.0. An indentationPerLevel of 0 can be used to eliminate all indentation and make an NSOutlineView appear more like an NSTableView.
*/
- (void)setIndentationPerLevel:(CGFloat)indentationPerLevel;
- (CGFloat)indentationPerLevel;

/* The indentation marker is the visual indicator that shows an item is expandable (i.e. disclosure triangle). The default value is YES.
*/
- (void)setIndentationMarkerFollowsCell:(BOOL)drawInCell; 
- (BOOL)indentationMarkerFollowsCell;

/* If autoresizesOutlineColumn is YES, then the outlineTableColumn will automatically resize when there is a new expanded child at a particular depth level. The default value is YES.
*/
- (void)setAutoresizesOutlineColumn:(BOOL)resize;
- (BOOL)autoresizesOutlineColumn;

/* Returns the frame of the outline cell for a particular row, considering the current indentation and indentationMarkerFollowsCell value. If 'row' is not an expandable row, it will return NSZeroRect. This method can be overridden by subclassers to return a custom frame for the outline button cell. If an empty rect is returned, no outline cell will be drawn for that row.
*/
- (NSRect)frameOfOutlineCellAtRow:(NSInteger)row NS_AVAILABLE_MAC(10_5); 

/* Drag and Drop
*/

/* To be used from validateDrop: in order to "re-target" the proposed drop.  To specify a drop on an item I, one would specify item=I, and index=NSOutlineViewDropOnItemIndex.  To specify a drop between child 2 and 3 of an item I, on would specify item=I, and index=3 (children are zero-base indexed).  To specify a drop on an un-expandable item I, one would specify item=I, and index=NSOutlineViewDropOnItemIndex.
*/
- (void)setDropItem:(id)item dropChildIndex:(NSInteger)index;

/* This method returns YES to indicate that auto expanded items should return to their original collapsed state.  Override this method to provide custom behavior.  'deposited' tells wether or not the drop terminated due to a successful drop (as indicated by the return value from acceptDrop:).  Note that exiting the view will be treated the same as a failed drop.
*/
- (BOOL)shouldCollapseAutoExpandedItemsForDeposited:(BOOL)deposited;

/* Persistence. The value for autosaveExpandedItems is saved out in the nib file on Mac OS 10.5 or higher. The default value is NO. Calling setAutosaveExpandedItems:YES requires you to implement outlineView:itemForPersistentObject: and outlineView:persistentObjectForItem:.
*/
- (BOOL)autosaveExpandedItems;
- (void)setAutosaveExpandedItems:(BOOL)save;

#pragma mark -
#pragma mark ***** Animated Insert / Remove / Move Support *****

/* This method parallels TableView's -insertRowIndexes:withAnimation:, and is used in a way similar to NSMutableArray's -insertObjects:atIndexes: This method inserts each a new item at 'indexes' in 'parent'. 'parent' and be nil to insert items into the root of the OutlineView. The operation will not do anything if 'parent' is not expanded. The actual item values are determined by the dataSource methods -outlineView:child:ofItem: (note that this will only be called after an -endUpdates happens to ensure dataSource integrity). Calling this method multiple times within the same beginUpdates/endUpdates block is allowed; new insertions will move previously inserted new items, just like modifying an array. Inserting an index beyond what is available will throw an exception.  The "Cell Based TableView" must first call -beginUpdates before calling this method. 
 */
- (void)insertItemsAtIndexes:(NSIndexSet *)indexes inParent:(id)parent withAnimation:(NSTableViewAnimationOptions)animationOptions NS_AVAILABLE_MAC(10_7);

/* This method parallels TableView's -removeRowsAtIndexes:withAnimation:, and is used similar to NSMutableArray's -removeObjectsAtIndexes:. The items at the given indexes will be removed from the parent. The operation will not do anything if 'parent' is not expanded. If one of the children items is expanded, then all of its children rows will also be removed. Calling this method multiple times within the same beginUpdates/endUpdates block is allowed; changes work just like modifying an array. Deleting an index beyond what is available will throw an exception.  The "Cell Based TableView" must first call -beginUpdates before calling this method. 
 */
- (void)removeItemsAtIndexes:(NSIndexSet *)indexes inParent:(id)parent withAnimation:(NSTableViewAnimationOptions)animationOptions NS_AVAILABLE_MAC(10_7);

/* This method parallels TableView's -moveRowAtIndex:toIndex:. The item located at 'fromIndex' is moved from the existing 'oldParent' to the given index in 'newParent'. 'newParent' can be the same as 'oldParent' to reorder an item within the same parent. This method can be called multiple times within the same beginUpdates/endUpdates block. Moving from an invalid index, or to an invalid index will throw an exception.  The "Cell Based TableView" must first call -beginUpdates before calling this method. 
 */
- (void)moveItemAtIndex:(NSInteger)fromIndex inParent:(id)oldParent toIndex:(NSInteger)toIndex inParent:(id)newParent NS_AVAILABLE_MAC(10_7);

/* Modifications to an OutlineView should be done with the insertItems:/deleteItems:/moveItem: methods, and not the NSTableView primatives. Internally, these methods are used in the implementation, and while they are unavailable for callers they can be overridden by subclasses.
 */
- (void)insertRowsAtIndexes:(NSIndexSet *)indexes withAnimation:(NSTableViewAnimationOptions)animationOptions UNAVAILABLE_ATTRIBUTE;
- (void)removeRowsAtIndexes:(NSIndexSet *)indexes withAnimation:(NSTableViewAnimationOptions)animationOptions UNAVAILABLE_ATTRIBUTE;
- (void)moveRowAtIndex:(NSInteger)oldIndex toIndex:(NSInteger)newIndex UNAVAILABLE_ATTRIBUTE;

@end

#pragma mark -

/* Data Source Note: Specifying nil as the item will refer to the "root" item(s).
*/
@protocol NSOutlineViewDataSource <NSObject>
@optional

#pragma mark -
#pragma mark ***** Required Methods (unless bindings is used) *****

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item;
- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item;
- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item;

/* NOTE: this method is optional for the View Based OutlineView.
 */
- (id)outlineView:(NSOutlineView *)outlineView objectValueForTableColumn:(NSTableColumn *)tableColumn byItem:(id)item;

#pragma mark -
#pragma mark ***** Optional Methods *****

/* View Based OutlineView: This method is not applicable.
 */
- (void)outlineView:(NSOutlineView *)outlineView setObjectValue:(id)object forTableColumn:(NSTableColumn *)tableColumn byItem:(id)item;

- (id)outlineView:(NSOutlineView *)outlineView itemForPersistentObject:(id)object;
- (id)outlineView:(NSOutlineView *)outlineView persistentObjectForItem:(id)item;

/* Optional - Sorting Support
    This is the indication that sorting needs to be done. Typically the data source will sort its data, reload, and adjust selections.
*/
- (void)outlineView:(NSOutlineView *)outlineView sortDescriptorsDidChange:(NSArray *)oldDescriptors;

/* Optional - Drag and Drop support
*/

/* Dragging Source Support - Required for multi-image dragging. Implement this method to allow the table to be an NSDraggingSource that supports multiple item dragging. Return a custom object that implements NSPasteboardWriting (or simply use NSPasteboardItem). If this method is implemented, then outlineView:writeItems:toPasteboard: will not be called.
 */
- (id <NSPasteboardWriting>)outlineView:(NSOutlineView *)outlineView pasteboardWriterForItem:(id)item NS_AVAILABLE_MAC(10_7);

/* Dragging Source Support - Optional. Implement this method know when the dragging session is about to begin and to potentially modify the dragging session. 'draggedItems' is an array of items that we dragged, excluding items that were not dragged due to outlineView:pasteboardWriterForItem: returning nil. This array will directly match the pasteboard writer array used to begin the dragging session with [NSView beginDraggingSessionWithItems:event:source]. Hence, the order is deterministic, and can be used in -outlineView:acceptDrop:item:childIndex: when enumerating the NSDraggingInfo's pasteboard classes. 
 */
- (void)outlineView:(NSOutlineView *)outlineView draggingSession:(NSDraggingSession *)session willBeginAtPoint:(NSPoint)screenPoint forItems:(NSArray *)draggedItems NS_AVAILABLE_MAC(10_7);

/* Dragging Source Support - Optional. Implement this method know when the dragging session has ended. This delegate method can be used to know when the dragging source operation ended at a specific location, such as the trash (by checking for an operation of NSDragOperationDelete).
 */
- (void)outlineView:(NSOutlineView *)outlineView draggingSession:(NSDraggingSession *)session endedAtPoint:(NSPoint)screenPoint operation:(NSDragOperation)operation NS_AVAILABLE_MAC(10_7);

/* Dragging Source Support - Optional for single-image dragging. This method is called after it has been determined that a drag should begin, but before the drag has been started.  To refuse the drag, return NO.  To start a drag, return YES and place the drag data onto the pasteboard (data, owner, etc...).  The drag image and other drag related information will be set up and provided by the outline view once this call returns with YES.  The items array is the list of items that will be participating in the drag.
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView writeItems:(NSArray *)items toPasteboard:(NSPasteboard *)pasteboard;

/* Dragging Destination Support - Required for multi-image dragging. Implement this method to allow the table to update dragging items as they are dragged over the view. Typically this will involve calling [draggingInfo enumerateDraggingItemsWithOptions:forView:classes:searchOptions:usingBlock:] and setting the draggingItem's imageComponentsProvider to a proper image based on the content. For View Based TableViews, one can use NSTableCellView's -draggingImageComponents and -draggingImageFrame.
 */
- (void)outlineView:(NSOutlineView *)outlineView updateDraggingItemsForDrag:(id <NSDraggingInfo>)draggingInfo NS_AVAILABLE_MAC(10_7);

/* Dragging Destination Support - This method is used by NSOutlineView to determine a valid drop target. Based on the mouse position, the outline view will suggest a proposed child 'index' for the drop to happen as a child of 'item'. This method must return a value that indicates which NSDragOperation the data source will perform. The data source may "re-target" a drop, if desired, by calling setDropItem:dropChildIndex: and returning something other than NSDragOperationNone. One may choose to re-target for various reasons (eg. for better visual feedback when inserting into a sorted position). On Leopard linked applications, this method is called only when the drag position changes or the dragOperation changes (ie: a modifier key is pressed). Prior to Leopard, it would be called constantly in a timer, regardless of attribute changes.
*/
- (NSDragOperation)outlineView:(NSOutlineView *)outlineView validateDrop:(id <NSDraggingInfo>)info proposedItem:(id)item proposedChildIndex:(NSInteger)index;

/* Dragging Destination Support - This method is called when the mouse is released over an outline view that previously decided to allow a drop via the validateDrop method. The data source should incorporate the data from the dragging pasteboard at this time. 'index' is the location to insert the data as a child of 'item', and are the values previously set in the validateDrop: method.
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView acceptDrop:(id <NSDraggingInfo>)info item:(id)item childIndex:(NSInteger)index;

/* Dragging Destination Support - NSOutlineView data source objects can support file promised drags via by adding  NSFilesPromisePboardType to the pasteboard in outlineView:writeItems:toPasteboard:.  NSOutlineView implements -namesOfPromisedFilesDroppedAtDestination: to return the results of this data source method.  This method should returns an array of filenames for the created files (filenames only, not full paths).  The URL represents the drop location.  For more information on file promise dragging, see documentation on the NSDraggingSource protocol and -namesOfPromisedFilesDroppedAtDestination:.
*/
- (NSArray *)outlineView:(NSOutlineView *)outlineView namesOfPromisedFilesDroppedAtDestination:(NSURL *)dropDestination forDraggedItems:(NSArray *)items;

@end

#pragma mark -

@protocol NSOutlineViewDelegate <NSControlTextEditingDelegate>
@optional

#pragma mark -
#pragma mark ***** View Based TableView/OutlineView Support *****

/* View Based OutlineView: See the delegate method -tableView:viewForTableColumn:row: in NSTableView.
 */
- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)tableColumn item:(id)item NS_AVAILABLE_MAC(10_7);

/* View Based OutlineView: See the delegate method -tableView:rowViewForRow: in NSTableView.
 */
- (NSTableRowView *)outlineView:(NSOutlineView *)outlineView rowViewForItem:(id)item NS_AVAILABLE_MAC(10_7);

/* View Based OutlineView: This delegate method can be used to know when a new 'rowView' has been added to the table. At this point, you can choose to add in extra views, or modify any properties on 'rowView'.
 */
- (void)outlineView:(NSOutlineView *)outlineView didAddRowView:(NSTableRowView *)rowView forRow:(NSInteger)row NS_AVAILABLE_MAC(10_7);

/* View Based OutlineView: This delegate method can be used to know when 'rowView' has been removed from the table. The removed 'rowView' may be reused by the table so any additionally inserted views should be removed at this point. A 'row' parameter is included. 'row' will be '-1' for rows that are being deleted from the table and no longer have a valid row, otherwise it will be the valid row that is being removed due to it being moved off screen.
 */
- (void)outlineView:(NSOutlineView *)outlineView didRemoveRowView:(NSTableRowView *)rowView forRow:(NSInteger)row NS_AVAILABLE_MAC(10_7);

#pragma mark -
#pragma mark ***** Regular Delegate Methods *****

/* NSOutlineView replacements for NSTableView delegate methods.
*/
- (void)outlineView:(NSOutlineView *)outlineView willDisplayCell:(id)cell forTableColumn:(NSTableColumn *)tableColumn item:(id)item;
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldEditTableColumn:(NSTableColumn *)tableColumn item:(id)item;
- (BOOL)selectionShouldChangeInOutlineView:(NSOutlineView *)outlineView;

/* Optional - Return YES if 'item' should be selected and 'NO' if it should not. For better performance, and greater control, it is recommended that you use outlineView:selectionIndexesForProposedSelection:. 
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectItem:(id)item;

/* Optional - Return a set of new indexes to select when the user changes the selection with the keyboard or mouse. If implemented, this method will be called instead of outlineView:shouldSelectItem:. This method may be called multiple times with one new index added to the existing selection to find out if a particular index can be selected when the user is extending the selection with the keyboard or mouse. Note that 'proposedSelectionIndexes' will contain the entire newly suggested selection, and you can return the existing selection to avoid changing the selection.
*/
- (NSIndexSet *)outlineView:(NSOutlineView *)outlineView selectionIndexesForProposedSelection:(NSIndexSet *)proposedSelectionIndexes NS_AVAILABLE_MAC(10_5);

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldSelectTableColumn:(NSTableColumn *)tableColumn;

- (void)outlineView:(NSOutlineView *)outlineView mouseDownInHeaderOfTableColumn:(NSTableColumn *)tableColumn;
- (void)outlineView:(NSOutlineView *)outlineView didClickTableColumn:(NSTableColumn *)tableColumn;
- (void)outlineView:(NSOutlineView *)outlineView didDragTableColumn:(NSTableColumn *)tableColumn;

/* Optional - Tool Tip support
    When the user pauses over a cell, the value returned from this method will be displayed in a tooltip.  'point' represents the current mouse location in view coordinates.  If you don't want a tooltip at that location, return nil or the empty string.  On entry, 'rect' represents the proposed active area of the tooltip.  By default, rect is computed as [cell drawingRectForBounds:cellFrame].  To control the default active area, you can modify the 'rect' parameter.
*/
- (NSString *)outlineView:(NSOutlineView *)outlineView toolTipForCell:(NSCell *)cell rect:(NSRectPointer)rect tableColumn:(NSTableColumn *)tableColumn item:(id)item mouseLocation:(NSPoint)mouseLocation;

/* Optional - Variable Row Heights
    Implement this method to support a table with varying row heights. The height returned by this method should not include intercell spacing and must be greater than zero. Performance Considerations: For large tables in particular, you should make sure that this method is efficient. NSTableView may cache the values this method returns, but this should NOT be depended on, as all values may not be cached. To signal a row height change, call -noteHeightOfRowsWithIndexesChanged:. For a given row, the same row height should always be returned until -noteHeightOfRowsWithIndexesChanged: is called, otherwise unpredicable results will happen. NSTableView automatically invalidates its entire row height cache in -reloadData, and -noteNumberOfRowsChanged.
 */
- (CGFloat)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item;

/* Optional - Type select support
    Implement this method if you want to control the string that is used for type selection. You may want to change what is searched for based on what is displayed, or simply return nil for that row and/or column to not be searched. By default, all cells with text in them are searched. The default value when this delegate method is not implemented is [[outlineView preparedCellForColumn:tableColumn row:[outlineView rowForItem:item]] stringValue], and this value can be returned from the delegate method if desired.
*/
- (NSString *)outlineView:(NSOutlineView *)outlineView typeSelectStringForTableColumn:(NSTableColumn *)tableColumn item:(id)item NS_AVAILABLE_MAC(10_5);

/* Optional - Type select support
    Implement this method if you want to control how type selection works. Return the first item that matches the searchString from within the range of startItem to endItem. It is possible for endItem to be less than startItem if the search will wrap. Return nil when there is no match. Include startItem as a possible match, but do not include endItem. It is not necessary to implement this method in order to support type select.
*/
- (id)outlineView:(NSOutlineView *)outlineView nextTypeSelectMatchFromItem:(id)startItem toItem:(id)endItem forString:(NSString *)searchString NS_AVAILABLE_MAC(10_5);

/* Optional - Type select support
    Implement this method if you would like to prevent a type select from happening based on the current event and current search string. Generally, this will be called from keyDown: and the event will be a key event. The search string will be nil if no type select has began. 
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldTypeSelectForEvent:(NSEvent *)event withCurrentSearchString:(NSString *)searchString NS_AVAILABLE_MAC(10_5);

/* Optional - Expansion ToolTip support
    Implement this method and return NO to prevent an expansion tooltip from appearing for a particular cell at 'item' in 'tableColumn'. See NSCell.h for more information on expansion tool tips. 
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldShowCellExpansionForTableColumn:(NSTableColumn *)tableColumn item:(id)item NS_AVAILABLE_MAC(10_5);

/*  Optional - Custom tracking support
    It is possible to control the ability to track a cell or not. Normally, only selectable or selected cells can be tracked. If you implement this method, cells which are not selectable or selected can be tracked, and vice-versa. For instance, this allows you to have an NSButtonCell in a table which does not change the selection, but can still be clicked on and tracked.
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldTrackCell:(NSCell *)cell forTableColumn:(NSTableColumn *)tableColumn item:(id)item NS_AVAILABLE_MAC(10_5);

/*  Optional - Different cells for each row
    A different data cell can be returned for any particular tableColumn and item, or a cell that will be used for the entire row (a full width cell). The returned cell should properly implement copyWithZone:, since the cell may be copied by NSTableView. If the tableColumn is non-nil, you should return a cell, and generally you will want to default to returning the result from [tableColumn dataCellForRow:row].

    When each row (identified by the item) is being drawn, this method will first be called with a nil tableColumn. At this time, you can return a cell that will be used to draw the entire row, acting like a group. If you do return a cell for the 'nil' tableColumn, be prepared to have the other corresponding datasource and delegate methods to be called with a 'nil' tableColumn value. If don't return a cell, the method will be called once for each tableColumn in the tableView, as usual.
*/
- (NSCell *)outlineView:(NSOutlineView *)outlineView dataCellForTableColumn:(NSTableColumn *)tableColumn item:(id)item NS_AVAILABLE_MAC(10_5);

/* Optional - Group rows. 
    Implement this method and return YES to indicate a particular row should have the "group row" style drawn for that row. If the cell in that row is an NSTextFieldCell and contains only a stringValue, the "group row" style attributes will automatically be applied for that cell. 
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item NS_AVAILABLE_MAC(10_5);

/* Optional - Controlling expanding/collapsing of items.
    Called when the outlineView is about to expand 'item'. Implementations of this method should be fast. This method may be called multiple times if a given 'item' has children that are also being expanded. If NO is returned, 'item' will not be expanded, nor will its children (even if -[outlineView expandItem:item expandChildren:YES] is called).
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldExpandItem:(id)item;

/* Optional - Controlling expanding/collapsing of items.
    Called when the outlineView is about to collapse 'item'. Implementations of this method should be fast. If NO is returned, 'item' will not be collapsed, nor will its children (even if -[outlineView collapseItem:item collapseChildren:YES] is called).
*/
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldCollapseItem:(id)item;

/* Optional - OutlineCell (disclosure triangle button cell)
    Implement this method to customize the "outline cell" used for the disclosure triangle button. customization of the "outline cell" used for the disclosure triangle button. For instance, you can cause the button cell to always use a "dark" triangle by changing the cell's backgroundStyle with: [cell setBackgroundStyle:NSBackgroundStyleLight]
*/
- (void)outlineView:(NSOutlineView *)outlineView willDisplayOutlineCell:(id)cell forTableColumn:(NSTableColumn *)tableColumn item:(id)item;

/* Optional - Autosizing table columns
 Implement this method if you want to control how wide a column is made when the user double clicks on the resize divider. By default, NSTableView iterates every row in the table, accesses a cell via preparedCellAtRow:column:, and requests the "cellSize" to find the appropriate largest width to use. For large row counts, a monte carlo simulation is done instead of interating every row. For accurate performance, it is recommended that this method is implemented when using large tables. 
*/

- (CGFloat)outlineView:(NSOutlineView *)outlineView sizeToFitWidthOfColumn:(NSInteger)column NS_AVAILABLE_MAC(10_6);

/*  Optional - Control of column reordering.
 Specifies if the column can be reordered to a new location, or not. 'columnIndex' is the column that is being dragged. The actual NSTableColumn instance can be retrieved from the [tableView tableColumns] array. 'newColumnIndex' is the new proposed target location for 'columnIndex'. When a column is initially dragged by the user, the delegate is first called with a 'newColumnIndex' of -1. Returning NO will disallow that column from being reordered at all. Returning YES allows it to be reordered, and the delegate will be called again when the column reaches a new location. If this method is not implemented, all columns are considered reorderable. 
 */
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldReorderColumn:(NSInteger)columnIndex toColumn:(NSInteger)newColumnIndex NS_AVAILABLE_MAC(10_6);

/* Optional - Hiding the outline cell (disclosure triangle)
 Allows the delegate to decide if the outline cell (disclosure triangle) for 'item' should be displayed or not. This method will only be called for expandable rows. If 'NO' is returned,  -[outlineView frameOfOutlineCellAtRow:] will return NSZeroRect, causing the outline cell to be hidden. In addition, if 'NO' is returned, the row will not be collapsable by keyboard shortcuts.
 */
- (BOOL)outlineView:(NSOutlineView *)outlineView shouldShowOutlineCellForItem:(id)item NS_AVAILABLE_MAC(10_6);

/* Notifications - see comments below for more information about the @"NSObject" parameter in the userInfo dictionary.
 */
- (void)outlineViewSelectionDidChange:(NSNotification *)notification;
- (void)outlineViewColumnDidMove:(NSNotification *)notification;
- (void)outlineViewColumnDidResize:(NSNotification *)notification;
- (void)outlineViewSelectionIsChanging:(NSNotification *)notification;
- (void)outlineViewItemWillExpand:(NSNotification *)notification;
- (void)outlineViewItemDidExpand:(NSNotification *)notification;
- (void)outlineViewItemWillCollapse:(NSNotification *)notification;
- (void)outlineViewItemDidCollapse:(NSNotification *)notification;

@end


/* Notifications 
*/
APPKIT_EXTERN NSString *NSOutlineViewSelectionDidChangeNotification;
APPKIT_EXTERN NSString *NSOutlineViewColumnDidMoveNotification;                                // @"NSOldColumn", @"NSNewColumn"
APPKIT_EXTERN NSString *NSOutlineViewColumnDidResizeNotification;                // @"NSTableColumn", @"NSOldWidth"
APPKIT_EXTERN NSString *NSOutlineViewSelectionIsChangingNotification;


/* Note for the following NSOutlineViewItem*Notifications:
   The 'userInfo' dictionary in the notification will have an @"NSObject" key where the value is the changed (id)item.
*/
APPKIT_EXTERN NSString *NSOutlineViewItemWillExpandNotification;
APPKIT_EXTERN NSString *NSOutlineViewItemDidExpandNotification;
APPKIT_EXTERN NSString *NSOutlineViewItemWillCollapseNotification;
APPKIT_EXTERN NSString *NSOutlineViewItemDidCollapseNotification;

