
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef enum{
	PullLoadMorePulling = 0,
	PullLoadMoreNormal,
	PullLoadMoreLoading,
} PullLoadMoreState;

@protocol LoadMoreTableFooterDelegate;

@interface LoadMoreTableFooterView : UIView {
	
	id _delegate;
	PullLoadMoreState _state;
	CALayer *_arrowImage;
	UIActivityIndicatorView *_activityView;
}

@property(nonatomic,copy) UILabel *statusLabel;

@property(nonatomic,assign) id <LoadMoreTableFooterDelegate> delegate;

- (id)initWithFrame:(CGRect)frame arrowImageName:(NSString *)arrow textColor:(UIColor *)textColor;

- (void)loadMoreScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)loadMoreScrollViewDidEndDragging:(UIScrollView *)scrollView;
- (void)loadMoreScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;

@end

@protocol LoadMoreTableFooterDelegate

- (void)loadMoreTableFooterDidTriggerLoadMore:(LoadMoreTableFooterView*)view;
- (BOOL)loadMoreTableFooterDataSourceIsLoading:(LoadMoreTableFooterView*)view;


@end
